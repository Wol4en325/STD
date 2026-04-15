#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

struct Node
{
    double data;
    Node* next;
};

void push(Node* &top, double value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

double pop(Node* &top)
{
    double value = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return value;
}

bool isEmpty(Node* top)
{
    return top == NULL;
}

void printStack(Node* top)
{
    Node* current = top;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void freeStack(Node* &top)
{
    while (!isEmpty(top))
        pop(top);
}

int main()
{
    srand(time(0));

    Node* stack = NULL;
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        double value = -6.0 + (double)(rand() % 1700) / 100.0;
        push(stack, value);
    }

    cout << "Original stack: ";
    printStack(stack);

    double threshold;
    cout << "Enter threshold value: ";
    cin >> threshold;

    Node* tempStack = NULL;
    while (!isEmpty(stack))
    {
        double value = pop(stack);
        if (value >= threshold)
            push(tempStack, value);
    }

    Node* newStack = NULL;
    while (!isEmpty(tempStack))
    {
        double value = pop(tempStack);
        push(newStack, value);
    }

    cout << "New stack (elements >= " << threshold << "): ";
    printStack(newStack);

    double sum = 0;
    int count = 0;
    Node* current = newStack;
    while (current != NULL)
    {
        sum += current->data;
        count++;
        current = current->next;
    }

    if (count > 0)
        cout << "Average: " << sum / count << endl;
    else
        cout << "New stack is empty." << endl;

    freeStack(newStack);
    cout << "Memory freed." << endl;

    return 0;
}
