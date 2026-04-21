#include <iostream>
#include <cstring>

using namespace std;

struct Node
{
    char name[50];
    char department[50];
    double salary;
    Node* next;
    Node* prev;
};

Node* addToEnd(Node* &head, Node* &tail, char name[], char dept[], double salary)
{
    Node* newNode = new Node;
    strcpy(newNode->name, name);
    strcpy(newNode->department, dept);
    newNode->salary = salary;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    return head;
}

void printForward(Node* head)
{
    Node* current = head;
    while (current != NULL)
    {
        cout << current->name << " | " << current->department << " | $" << current->salary << endl;
        current = current->next;
    }
}

void printBackward(Node* tail)
{
    Node* current = tail;
    while (current != NULL)
    {
        cout << current->name << " | " << current->department << " | $" << current->salary << endl;
        current = current->prev;
    }
}

double calcAverage(Node* head)
{
    double sum = 0;
    int count = 0;
    Node* current = head;
    while (current != NULL)
    {
        sum += current->salary;
        count++;
        current = current->next;
    }
    if (count == 0)
        return 0;
    return sum / count;
}

void freeList(Node* &head, Node* &tail)
{
    while (head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = NULL;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    int n;
    cout << "Enter number of workers: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        char name[50];
        char dept[50];
        double salary;

        cout << endl << "Worker " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin.getline(name, 50);
        cout << "Department: ";
        cin.getline(dept, 50);
        cout << "Salary: ";
        cin >> salary;
        cin.ignore();

        addToEnd(head, tail, name, dept, salary);
    }

    double avg = calcAverage(head);
    cout << endl << "Average salary: $" << avg << endl;

    Node* headAbove = NULL;
    Node* tailAbove = NULL;
    Node* headBelow = NULL;
    Node* tailBelow = NULL;

    Node* current = head;
    while (current != NULL)
    {
        if (current->salary > avg)
            addToEnd(headAbove, tailAbove, current->name, current->department, current->salary);
        else
            addToEnd(headBelow, tailBelow, current->name, current->department, current->salary);
        current = current->next;
    }

    cout << endl << "Workers with salary ABOVE average (forward):" << endl;
    printForward(headAbove);
    cout << endl << "Workers with salary ABOVE average (backward):" << endl;
    printBackward(tailAbove);

    cout << endl << "Workers with salary BELOW or EQUAL average (forward):" << endl;
    printForward(headBelow);
    cout << endl << "Workers with salary BELOW or EQUAL average (backward):" << endl;
    printBackward(tailBelow);

    char newName[50];
    char newDept[50];
    double newSalary;

    cout << endl << "Add new worker to the above-average list:" << endl;
    cout << "Name: ";
    cin.getline(newName, 50);
    cout << "Department: ";
    cin.getline(newDept, 50);
    cout << "Salary: ";
    cin >> newSalary;
    cin.ignore();

    addToEnd(headAbove, tailAbove, newName, newDept, newSalary);

    cout << endl << "Updated above-average list (forward):" << endl;
    printForward(headAbove);

    freeList(head, tail);
    freeList(headAbove, tailAbove);
    freeList(headBelow, tailBelow);
    cout << "Memory freed." << endl;

    return 0;
}
