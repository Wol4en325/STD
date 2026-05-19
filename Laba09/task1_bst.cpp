#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

bool search(Node* root, int value)
{
    if (root == NULL)
        return false;
    if (root->data == value)
        return true;
    if (value < root->data)
        return search(root->left, value);
    return search(root->right, value);
}

int depth(Node* root)
{
    if (root == NULL)
        return 0;

    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);

    if (leftDepth > rightDepth)
        return 1 + leftDepth;
    return 1 + rightDepth;
}

void printInOrder(Node* root)
{
    if (root == NULL)
        return;
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

void buildEvenOdd(Node* root, Node* &evenRoot, Node* &oddRoot)
{
    if (root == NULL)
        return;

    if (root->data % 2 == 0)
        evenRoot = insert(evenRoot, root->data);
    else
        oddRoot = insert(oddRoot, root->data);

    buildEvenOdd(root->left, evenRoot, oddRoot);
    buildEvenOdd(root->right, evenRoot, oddRoot);
}

void freeTree(Node* root)
{
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

bool used[10000];

int generateUnique(int a, int b)
{
    int value;
    do
    {
        value = a + rand() % (b - a + 1);
    } while (used[value - a]);
    used[value - a] = true;
    return value;
}

int main()
{
    srand(time(0));

    Node* root = NULL;
    Node* evenRoot = NULL;
    Node* oddRoot = NULL;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    int mode;
    cout << "Input mode (1 - manual, 2 - random): ";
    cin >> mode;

    if (mode == 1)
    {
        for (int i = 0; i < n; i++)
        {
            int value;
            cout << "Enter value " << i + 1 << ": ";
            cin >> value;

            if (search(root, value))
            {
                cout << "Value " << value << " already exists in tree. Skipping." << endl;
                i--;
            }
            else
            {
                root = insert(root, value);
            }
        }
    }
    else
    {
        int a, b;
        cout << "Enter range [a, b]: ";
        cin >> a >> b;

        while (b - a < n - 1)
        {
            cout << "Range too small. n must be <= b - a. Enter again: ";
            cin >> a >> b;
        }

        for (int i = 0; i < 10000; i++)
            used[i] = false;

        for (int i = 0; i < n; i++)
        {
            int value = generateUnique(a, b);
            root = insert(root, value);
        }
    }

    cout << endl << "Tree (in-order): ";
    printInOrder(root);
    cout << endl;
    cout << "Tree depth: " << depth(root) << endl;

    int searchVal;
    cout << endl << "Enter value to search: ";
    cin >> searchVal;
    if (search(root, searchVal))
        cout << "Value " << searchVal << " FOUND in tree." << endl;
    else
        cout << "Value " << searchVal << " NOT found." << endl;

    buildEvenOdd(root, evenRoot, oddRoot);

    cout << endl << "Even tree (in-order): ";
    printInOrder(evenRoot);
    cout << endl;
    cout << "Even tree depth: " << depth(evenRoot) << endl;

    cout << endl << "Odd tree (in-order): ";
    printInOrder(oddRoot);
    cout << endl;
    cout << "Odd tree depth: " << depth(oddRoot) << endl;

    freeTree(root);
    freeTree(evenRoot);
    freeTree(oddRoot);
    cout << endl << "Memory freed." << endl;

    return 0;
}
