#include <iostream>
#include <cstring>

using namespace std;

struct Node
{
    char cityName[50];
    int distance;
    Node* next;
};

Node* addToEnd(Node* head, char name[], int dist)
{
    Node* newNode = new Node;
    strcpy(newNode->cityName, name);
    newNode->distance = dist;
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
        cout << current->cityName << " - " << current->distance << " km" << endl;
        current = current->next;
    }
}

void findTwoFarthest(Node* head)
{
    Node* first = NULL;
    Node* second = NULL;

    Node* current = head;
    while (current != NULL)
    {
        if (first == NULL || current->distance > first->distance)
        {
            second = first;
            first = current;
        }
        else if (second == NULL || current->distance > second->distance)
        {
            second = current;
        }
        current = current->next;
    }

    cout << "Two farthest cities from Kyiv:" << endl;
    if (first != NULL)
        cout << "1. " << first->cityName << " - " << first->distance << " km" << endl;
    if (second != NULL)
        cout << "2. " << second->cityName << " - " << second->distance << " km" << endl;
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
    cout << "Enter number of cities: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        char name[50];
        int dist;
        cout << "City name: ";
        cin.getline(name, 50);
        cout << "Distance from Kyiv (km): ";
        cin >> dist;
        cin.ignore();
        head = addToEnd(head, name, dist);
    }

    cout << endl << "City list:" << endl;
    printList(head);

    cout << endl;
    findTwoFarthest(head);

    char foreignName[50];
    int foreignDist;
    cout << endl << "Enter foreign city name: ";
    cin.getline(foreignName, 50);
    cout << "Distance from Kyiv (km): ";
    cin >> foreignDist;

    head = addToEnd(head, foreignName, foreignDist);

    cout << endl << "Updated list:" << endl;
    printList(head);

    freeList(head);
    cout << "Memory freed." << endl;

    return 0;
}
