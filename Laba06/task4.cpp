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

bool isQueueEmpty(Queue q)
{
    return q.front == NULL;
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

void freeQueue(Queue &q)
{
    while (!isQueueEmpty(q))
        dequeue(q);
}

bool cityAlreadyInQueue(Queue q, char city[])
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

int main()
{
    int n;
    cout << "Enter number of teams: ";
    cin >> n;
    cin.ignore();

    Queue original;
    initQueue(original);

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
        enqueue(original, t);
    }

    cout << endl << "Original queue:" << endl;
    printQueue(original);

    Queue tempQueue;
    initQueue(tempQueue);

    Team leader = original.front->data;
    Team outsider = original.front->data;
    Queue uniqueCities;
    initQueue(uniqueCities);

    int pointsThreshold;
    cout << endl << "Enter points threshold: ";
    cin >> pointsThreshold;

    Queue aboveThreshold;
    initQueue(aboveThreshold);

    while (!isQueueEmpty(original))
    {
        Team t = dequeue(original);

        if (t.points > leader.points)
            leader = t;
        if (t.points < outsider.points)
            outsider = t;

        if (!cityAlreadyInQueue(uniqueCities, t.city))
            enqueue(uniqueCities, t);

        if (t.points > pointsThreshold)
            enqueue(aboveThreshold, t);

        enqueue(tempQueue, t);
    }

    while (!isQueueEmpty(tempQueue))
    {
        Team t = dequeue(tempQueue);
        enqueue(original, t);
    }

    cout << endl << "Leader: " << leader.name << " (" << leader.points << " points)" << endl;
    cout << "Outsider: " << outsider.name << " (" << outsider.points << " points)" << endl;

    cout << endl << "One team per city:" << endl;
    printQueue(uniqueCities);

    cout << endl << "Teams with more than " << pointsThreshold << " points:" << endl;
    if (isQueueEmpty(aboveThreshold))
        cout << "No teams found." << endl;
    else
        printQueue(aboveThreshold);

    cout << endl << "Restored original queue:" << endl;
    printQueue(original);

    freeQueue(original);
    freeQueue(uniqueCities);
    freeQueue(aboveThreshold);
    cout << "Memory freed." << endl;

    return 0;
}
