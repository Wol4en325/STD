#include <iostream>
#include <cstring>

using namespace std;

struct Node
{
    char title[50];
    char author[50];
    int year;
    Node* next;
    Node* prev;
};

Node* addToEnd(Node* &head, Node* &tail, char title[], char author[], int year)
{
    Node* newNode = new Node;
    strcpy(newNode->title, title);
    strcpy(newNode->author, author);
    newNode->year = year;
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
        cout << "\"" << current->title << "\" by " << current->author << " (" << current->year << ")" << endl;
        current = current->next;
    }
}

void printBackward(Node* tail)
{
    Node* current = tail;
    while (current != NULL)
    {
        cout << "\"" << current->title << "\" by " << current->author << " (" << current->year << ")" << endl;
        current = current->prev;
    }
}

void mergeLists(Node* &head1, Node* &tail1, Node* head2)
{
    if (head2 == NULL)
        return;

    if (head1 == NULL)
    {
        head1 = head2;
        return;
    }

    tail1->next = head2;
    head2->prev = tail1;

    Node* current = head2;
    while (current->next != NULL)
        current = current->next;
    tail1 = current;
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

    int n;
    cout << "Enter number of books for list 1: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        char title[50], author[50];
        int year;
        cout << endl << "Book " << i + 1 << " (list 1):" << endl;
        cout << "Title: ";
        cin.getline(title, 50);
        cout << "Author: ";
        cin.getline(author, 50);
        cout << "Year: ";
        cin >> year;
        cin.ignore();
        addToEnd(head1, tail1, title, author, year);
    }

    int m;
    cout << endl << "Enter number of books for list 2: ";
    cin >> m;
    cin.ignore();

    for (int i = 0; i < m; i++)
    {
        char title[50], author[50];
        int year;
        cout << endl << "Book " << i + 1 << " (list 2):" << endl;
        cout << "Title: ";
        cin.getline(title, 50);
        cout << "Author: ";
        cin.getline(author, 50);
        cout << "Year: ";
        cin >> year;
        cin.ignore();
        addToEnd(head2, tail2, title, author, year);
    }

    cout << endl << "List 1 (forward):" << endl;
    printForward(head1);
    cout << endl << "List 1 (backward):" << endl;
    printBackward(tail1);

    cout << endl << "List 2 (forward):" << endl;
    printForward(head2);
    cout << endl << "List 2 (backward):" << endl;
    printBackward(tail2);

    mergeLists(head1, tail1, head2);

    cout << endl << "Merged list (forward):" << endl;
    printForward(head1);

    freeList(head1, tail1);
    cout << "Memory freed." << endl;

    return 0;
}
