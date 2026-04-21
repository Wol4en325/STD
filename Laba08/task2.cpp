#include <iostream>
#include <cstring>

using namespace std;

struct Route
{
    int routeNumber;
    char destination[50];
    int passengers;
};

struct Node
{
    Route data;
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

void enqueue(Queue &q, Route r)
{
    Node* newNode = new Node;
    newNode->data = r;
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

Route dequeue(Queue &q)
{
    Route value = q.front->data;
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
        cout << "Route #" << current->data.routeNumber
             << " | To: " << current->data.destination
             << " | Passengers: " << current->data.passengers << endl;
        current = current->next;
    }
}

void mergeQueues(Queue &q1, Queue &q2)
{
    if (isQueueEmpty(q2))
        return;

    if (isQueueEmpty(q1))
    {
        q1 = q2;
        initQueue(q2);
        return;
    }

    q1.back->next = q2.front;
    q1.back = q2.back;
    initQueue(q2);
}

void printAbovePassengers(Queue q, int threshold)
{
    Node* current = q.front;
    bool found = false;
    while (current != NULL)
    {
        if (current->data.passengers > threshold)
        {
            cout << "Route #" << current->data.routeNumber
                 << " | To: " << current->data.destination
                 << " | Passengers: " << current->data.passengers << endl;
            found = true;
        }
        current = current->next;
    }
    if (!found)
        cout << "No routes found above threshold." << endl;
}

void freeQueue(Queue &q)
{
    while (!isQueueEmpty(q))
        dequeue(q);
}

int main()
{
    Queue q1, q2;
    initQueue(q1);
    initQueue(q2);

    int n;
    cout << "Enter number of routes for queue 1: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        Route r;
        cout << endl << "Route " << i + 1 << " (queue 1):" << endl;
        cout << "Route number: ";
        cin >> r.routeNumber;
        cin.ignore();
        cout << "Destination: ";
        cin.getline(r.destination, 50);
        cout << "Passengers: ";
        cin >> r.passengers;
        cin.ignore();
        enqueue(q1, r);
    }

    int m;
    cout << endl << "Enter number of routes for queue 2: ";
    cin >> m;
    cin.ignore();

    for (int i = 0; i < m; i++)
    {
        Route r;
        cout << endl << "Route " << i + 1 << " (queue 2):" << endl;
        cout << "Route number: ";
        cin >> r.routeNumber;
        cin.ignore();
        cout << "Destination: ";
        cin.getline(r.destination, 50);
        cout << "Passengers: ";
        cin >> r.passengers;
        cin.ignore();
        enqueue(q2, r);
    }

    mergeQueues(q1, q2);

    cout << endl << "Merged queue:" << endl;
    printQueue(q1);

    int threshold;
    cout << endl << "Enter passenger threshold: ";
    cin >> threshold;

    cout << endl << "Routes with more than " << threshold << " passengers:" << endl;
    printAbovePassengers(q1, threshold);

    cout << endl << "Serving first two routes..." << endl;
    for (int i = 0; i < 2 && !isQueueEmpty(q1); i++)
    {
        Route r = dequeue(q1);
        cout << "Served: Route #" << r.routeNumber << " to " << r.destination << endl;
    }

    cout << endl << "Queue after serving:" << endl;
    printQueue(q1);

    freeQueue(q1);
    cout << "Memory freed." << endl;

    return 0;
}
