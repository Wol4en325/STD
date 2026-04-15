#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

struct Node
{
    int data;
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

void enqueue(Queue &q, int value)
{
    Node* newNode = new Node;
    newNode->data = value;
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

int dequeue(Queue &q)
{
    int value = q.front->data;
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
        cout << current->data;
        if (current->next != NULL)
            cout << " -> ";
        current = current->next;
    }
    cout << endl;
}

void freeQueue(Queue &q)
{
    while (!isQueueEmpty(q))
        dequeue(q);
}

int main()
{
    srand(time(0));

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    Queue original;
    initQueue(original);

    for (int i = 0; i < n; i++)
    {
        int value = rand() % 50 + 1;
        enqueue(original, value);
    }

    cout << "Original queue: ";
    printQueue(original);

    Queue newQueue;
    initQueue(newQueue);

    while (!isQueueEmpty(original))
    {
        int value = dequeue(original);
        if (value % 2 == 0)
        {
            enqueue(newQueue, value);
            enqueue(newQueue, 100);
        }
    }

    cout << "New queue (even elements + 100 after each): ";
    printQueue(newQueue);

    double product = 1.0;
    int count = 0;
    Node* current = newQueue.front;
    while (current != NULL)
    {
        product *= current->data;
        count++;
        current = current->next;
    }

    if (count > 0)
        cout << "Geometric mean: " << pow(product, 1.0 / count) << endl;
    else
        cout << "New queue is empty." << endl;

    freeQueue(newQueue);
    cout << "Memory freed." << endl;

    return 0;
}
