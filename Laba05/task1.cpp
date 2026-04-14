#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* addToStart(Node* head, int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

Node* addToEnd(Node* head, int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    Node* current = head;
    while (current->next != NULL)
        current = current->next;

    current->next = newNode;
    return head;
}

Node* addAfterPosition(Node* head, int value, int position)
{
    Node* newNode = new Node;
    newNode->data = value;

    Node* current = head;
    int i = 1;
    while (current != NULL && i < position)
    {
        current = current->next;
        i++;
    }

    if (current == NULL)
    {
        delete newNode;
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

double findAverage(Node* head)
{
    double sum = 0;
    int count = 0;
    Node* current = head;
    while (current != NULL)
    {
        sum += current->data;
        count++;
        current = current->next;
    }
    if (count == 0)
        return 0;
    return sum / count;
}

Node* deleteFirstEven(Node* head)
{
    if (head == NULL)
        return NULL;

    if (head->data % 2 == 0)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* current = head;
    while (current->next != NULL)
    {
        if (current->next->data % 2 == 0)
        {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            return head;
        }
        current = current->next;
    }

    return head;
}

void printList(Node* head)
{
    Node* current = head;
    while (current != NULL)
    {
        cout << current->data;
        if (current->next != NULL)
            cout << " -> ";
        current = current->next;
    }
    cout << endl;
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

    cout << "Adding 10 to start" << endl;
    head = addToStart(head, 10);

    cout << "Adding 20 to end" << endl;
    head = addToEnd(head, 20);

    cout << "Adding 30 to end" << endl;
    head = addToEnd(head, 30);

    cout << "Adding 5 to start" << endl;
    head = addToStart(head, 5);

    cout << "Adding 15 after position 2 (middle)" << endl;
    head = addAfterPosition(head, 15, 2);

    cout << "List: ";
    printList(head);

    cout << "Average: " << findAverage(head) << endl;

    cout << "Deleting first even element..." << endl;
    head = deleteFirstEven(head);

    cout << "List after deletion: ";
    printList(head);

    freeList(head);
    cout << "Memory freed." << endl;

    return 0;
}
