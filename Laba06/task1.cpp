#include <iostream>
#include <cstring>

using namespace std;

struct Node
{
    char date[20];
    double temperature;
    Node* next;
    Node* prev;
};

Node* addToEnd(Node* &head, Node* &tail, char date[], double temp)
{
    Node* newNode = new Node;
    strcpy(newNode->date, date);
    newNode->temperature = temp;
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

void appendList(Node* &head1, Node* &tail1, Node* head2)
{
    Node* current = head2;
    while (current != NULL)
    {
        addToEnd(head1, tail1, current->date, current->temperature);
        current = current->next;
    }
}

void printForward(Node* head)
{
    Node* current = head;
    while (current != NULL)
    {
        cout << current->date << " : " << current->temperature << " C" << endl;
        current = current->next;
    }
}

void printBackward(Node* tail)
{
    Node* current = tail;
    while (current != NULL)
    {
        cout << current->date << " : " << current->temperature << " C" << endl;
        current = current->prev;
    }
}

void findMinMax(Node* head)
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node* maxNode = head;
    Node* minNode = head;
    Node* current = head->next;

    while (current != NULL)
    {
        if (current->temperature > maxNode->temperature)
            maxNode = current;
        if (current->temperature < minNode->temperature)
            minNode = current;
        current = current->next;
    }

    cout << "Max temperature: " << maxNode->temperature << " C on " << maxNode->date << endl;
    cout << "Min temperature: " << minNode->temperature << " C on " << minNode->date << endl;
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
    Node* head1 = NULL;
    Node* tail1 = NULL;
    Node* head2 = NULL;
    Node* tail2 = NULL;

    int n1;
    cout << "Enter number of records for list 1: ";
    cin >> n1;
    cin.ignore();

    for (int i = 0; i < n1; i++)
    {
        char date[20];
        double temp;
        cout << "Date (e.g. 01.01.2025): ";
        cin.getline(date, 20);
        cout << "Temperature: ";
        cin >> temp;
        cin.ignore();
        addToEnd(head1, tail1, date, temp);
    }

    int n2;
    cout << endl << "Enter number of records for list 2: ";
    cin >> n2;
    cin.ignore();

    for (int i = 0; i < n2; i++)
    {
        char date[20];
        double temp;
        cout << "Date (e.g. 01.02.2025): ";
        cin.getline(date, 20);
        cout << "Temperature: ";
        cin >> temp;
        cin.ignore();
        addToEnd(head2, tail2, date, temp);
    }

    appendList(head1, tail1, head2);

    cout << endl << "Merged list (forward):" << endl;
    printForward(head1);

    cout << endl << "Merged list (backward):" << endl;
    printBackward(tail1);

    cout << endl;
    findMinMax(head1);

    freeList(head1, tail1);
    freeList(head2, tail2);
    cout << "Memory freed." << endl;

    return 0;
}
