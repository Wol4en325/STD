#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Node
{
    int code;
    char name[50];
    double price;
    Node* left;
    Node* right;
};

Node* createNode(int code, char name[], double price)
{
    Node* newNode = new Node;
    newNode->code = code;
    strcpy(newNode->name, name);
    newNode->price = price;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int code, char name[], double price)
{
    if (root == NULL)
        return createNode(code, name, price);

    if (code < root->code)
        root->left = insert(root->left, code, name, price);
    else if (code > root->code)
        root->right = insert(root->right, code, name, price);

    return root;
}

double calcTotalPrice(Node* root, int &count)
{
    if (root == NULL)
        return 0;

    count++;
    return root->price + calcTotalPrice(root->left, count) + calcTotalPrice(root->right, count);
}

void countPerLevel(Node* root, int level, int counts[], int &maxLevel)
{
    if (root == NULL)
        return;

    counts[level]++;
    if (level > maxLevel)
        maxLevel = level;

    countPerLevel(root->left, level + 1, counts, maxLevel);
    countPerLevel(root->right, level + 1, counts, maxLevel);
}

Node* findNode(Node* root, int code)
{
    if (root == NULL)
        return NULL;
    if (root->code == code)
        return root;
    if (code < root->code)
        return findNode(root->left, code);
    return findNode(root->right, code);
}

void freeTree(Node* root)
{
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

void deleteChildren(Node* node)
{
    if (node == NULL)
        return;

    freeTree(node->left);
    freeTree(node->right);
    node->left = NULL;
    node->right = NULL;
}

void printInOrder(Node* root)
{
    if (root == NULL)
        return;
    printInOrder(root->left);
    cout << "Code: " << root->code << " | " << root->name << " | $" << root->price << endl;
    printInOrder(root->right);
}

int main()
{
    Node* root = NULL;

    ifstream file("computers.txt");
    if (!file)
    {
        cout << "File not found." << endl;
        return 1;
    }

    int code;
    char name[50];
    double price;

    while (file >> code >> name >> price)
        root = insert(root, code, name, price);

    file.close();

    cout << "Tree (in-order):" << endl;
    printInOrder(root);

    int count = 0;
    double total = calcTotalPrice(root, count);
    cout << endl << "Total items: " << count << endl;
    cout << "Average price: $" << total / count << endl;

    int counts[100] = {0};
    int maxLevel = 0;
    countPerLevel(root, 0, counts, maxLevel);

    cout << endl << "Nodes per level:" << endl;
    for (int i = 0; i <= maxLevel; i++)
        cout << "Level " << i << ": " << counts[i] << " node(s)" << endl;

    int searchCode;
    cout << endl << "Enter code to find and delete its children: ";
    cin >> searchCode;

    Node* found = findNode(root, searchCode);
    if (found != NULL)
    {
        cout << "Found: " << found->name << " | $" << found->price << endl;
        deleteChildren(found);
        cout << "Children deleted." << endl;
    }
    else
    {
        cout << "Code " << searchCode << " not found." << endl;
    }

    cout << endl << "Tree after deletion:" << endl;
    printInOrder(root);

    freeTree(root);
    cout << endl << "Memory freed." << endl;

    return 0;
}
