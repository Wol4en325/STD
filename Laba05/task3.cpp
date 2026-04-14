#include <iostream>
#include <cstring>

using namespace std;

struct Node
{
    char carName[50];
    int year;
    double price;
    Node* next;
};

Node* addToEnd(Node* head, char name[], int year, double price)
{
    Node* newNode = new Node;
    strcpy(newNode->carName, name);
    newNode->year = year;
    newNode->price = price;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    Node* current = head;
    while (current->next != NULL)
        current = current->next;

    current->next = newNode;
    return head;
}

void printList(Node* head)
{
    Node* current = head;
    while (current != NULL)
    {
        cout << current->carName << " | Year: " << current->year << " | Price: $" << current->price << endl;
        current = current->next;
    }
}

void printOldAndCheap(Node* head)
{
    int currentYear = 2025;
    bool found = false;

    Node* current = head;
    while (current != NULL)
    {
        int age = currentYear - current->year;
        if (age > 10 && current->price < 5000)
        {
            cout << current->carName << " | Year: " << current->year << " | Price: $" << current->price << endl;
            found = true;
        }
        current = current->next;
    }

    if (!found)
        cout << "No cars matching the criteria found." << endl;
}

void freeList(Node* head)
{
    while (head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    Node* head = NULL;

    int n;
    cout << "Enter number of cars: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        char name[50];
        int year;
        double price;

        cout << endl << "Car " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin.getline(name, 50);
        cout << "Year: ";
        cin >> year;
        cout << "Price ($): ";
        cin >> price;
        cin.ignore();

        head = addToEnd(head, name, year, price);
    }

    cout << endl << "Full car list:" << endl;
    printList(head);

    cout << endl << "Cars older than 10 years and cheaper than $5000:" << endl;
    printOldAndCheap(head);

    freeList(head);
    cout << endl << "Memory freed." << endl;

    return 0;
}
