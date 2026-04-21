#include <iostream>
#include <cstring>

using namespace std;

struct Team
{
    char name[50];
    char city[50];
    int points;
};

struct Node
{
    Team data;
    Node* next;
};

struct Queue
{
    Node* front;
    Node* back;
};

void initQueue(Queue &q)
{
    q.front = NULL;
    q.back = NULL;
}

bool isQueueEmpty(Queue q)
{
    return q.front == NULL;
}

void enqueue(Queue &q, Team t)
{
    Node* newNode = new Node;
    newNode->data = t;
    newNode->next = NULL;

    if (q.back == NULL)
    {
        q.front = newNode;
        q.back = newNode;
    }
    else
    {
        q.back->next = newNode;
        q.back = newNode;
    }
}

Team dequeue(Queue &q)
{
    Team value = q.front->data;
    Node* temp = q.front;
    q.front = q.front->next;
    if (q.front == NULL)
        q.back = NULL;
    delete temp;
    return value;
}

void printQueue(Queue q)
{
    Node* current = q.front;
    while (current != NULL)
    {
        cout << "Team: " << current->data.name
             << " | City: " << current->data.city
             << " | Points: " << current->data.points << endl;
        current = current->next;
    }
}

bool cityExists(Queue q, char city[])
{
    Node* current = q.front;
    while (current != NULL)
    {
        if (strcmp(current->data.city, city) == 0)
            return true;
        current = current->next;
    }
    return false;
}

void freeQueue(Queue &q)
{
    while (!isQueueEmpty(q))
        dequeue(q);
}

int main()
{
    int n;
    cout << "Enter number of teams: ";
    cin >> n;
    cin.ignore();

    Queue teams;
    initQueue(teams);

    for (int i = 0; i < n; i++)
    {
        Team t;
        cout << endl << "Team " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin.getline(t.name, 50);
        cout << "City: ";
        cin.getline(t.city, 50);
        cout << "Points: ";
        cin >> t.points;
        cin.ignore();
        enqueue(teams, t);
    }

    cout << endl << "All teams:" << endl;
    printQueue(teams);

    Queue tempQueue;
    initQueue(tempQueue);

    Queue uniqueCities;
    initQueue(uniqueCities);

    Team leader = teams.front->data;
    Team outsider = teams.front->data;

    while (!isQueueEmpty(teams))
    {
        Team t = dequeue(teams);

        if (t.points > leader.points)
            leader = t;
        if (t.points < outsider.points)
            outsider = t;

        if (!cityExists(uniqueCities, t.city))
            enqueue(uniqueCities, t);

        enqueue(tempQueue, t);
    }

    while (!isQueueEmpty(tempQueue))
    {
        Team t = dequeue(tempQueue);
        enqueue(teams, t);
    }

    cout << endl << "Cities of participants (no duplicates):" << endl;
    Node* current = uniqueCities.front;
    while (current != NULL)
    {
        cout << current->data.city << endl;
        current = current->next;
    }

    cout << endl << "Leader: " << leader.name << " (" << leader.points << " points)" << endl;
    cout << "Outsider: " << outsider.name << " (" << outsider.points << " points)" << endl;

    freeQueue(teams);
    freeQueue(uniqueCities);
    cout << "Memory freed." << endl;

    return 0;
}
