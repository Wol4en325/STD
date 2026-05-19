#include <iostream>

using namespace std;

int main()
{
    int n = 6;

    int matrix[6][6] = {
        {0, 4, 3, 0, 0, 0},
        {4, 0, 0, 3, 1, 0},
        {3, 0, 0, 0, 5, 8},
        {0, 3, 0, 0, 0, 6},
        {0, 1, 5, 0, 0, 2},
        {0, 0, 8, 6, 2, 0}
    };

    cout << "=== Adjacency matrix ===" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;

    cout << "=== Adjacency list ===" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Vertex " << i + 1 << ": ";
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] != 0)
            {
                cout << "-> " << j + 1 << " (weight: " << matrix[i][j] << ") ";
            }
        }
        cout << endl;
    }

    cout << endl;

    cout << "=== Number of edges ===" << endl;
    int edgeCount = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (matrix[i][j] != 0)
            {
                edgeCount++;
            }
        }
    }
    cout << "Total edges: " << edgeCount << endl;

    cout << endl;

    cout << "=== Vertex degrees ===" << endl;
    int degree[6] = {0, 0, 0, 0, 0, 0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] != 0)
            {
                degree[i]++;
            }
        }
        cout << "Vertex " << i + 1 << " degree: " << degree[i] << endl;
    }

    int maxDegree = degree[0];
    int minDegree = degree[0];
    int maxVertex = 0;
    int minVertex = 0;

    for (int i = 1; i < n; i++)
    {
        if (degree[i] > maxDegree)
        {
            maxDegree = degree[i];
            maxVertex = i;
        }
        if (degree[i] < minDegree)
        {
            minDegree = degree[i];
            minVertex = i;
        }
    }

    cout << "Max degree: vertex " << maxVertex + 1 << " (degree: " << maxDegree << ")" << endl;
    cout << "Min degree: vertex " << minVertex + 1 << " (degree: " << minDegree << ")" << endl;

    cout << endl;

    cout << "=== Vertices with equal number of connections ===" << endl;
    bool foundEqual = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (degree[i] == degree[j])
            {
                cout << "Vertex " << i + 1 << " and vertex " << j + 1;
                cout << " both have degree: " << degree[i] << endl;
                foundEqual = true;
            }
        }
    }

    if (!foundEqual)
    {
        cout << "No vertices with equal degree found." << endl;
    }

    cout << endl;

    cout << "=== Three cities with smallest total distance ===" << endl;
    int minTotal = -1;
    int bestA = -1;
    int bestB = -1;
    int bestC = -1;

    for (int a = 0; a < n; a++)
    {
        for (int b = a + 1; b < n; b++)
        {
            for (int c = b + 1; c < n; c++)
            {
                if (matrix[a][b] != 0 && matrix[b][c] != 0 && matrix[a][c] != 0)
                {
                    int total = matrix[a][b] + matrix[b][c] + matrix[a][c];
                    if (minTotal == -1 || total < minTotal)
                    {
                        minTotal = total;
                        bestA = a;
                        bestB = b;
                        bestC = c;
                    }
                }
            }
        }
    }

    if (bestA != -1)
    {
        cout << "Cities: " << bestA + 1 << ", " << bestB + 1 << ", " << bestC + 1 << endl;
        cout << "Total distance: " << minTotal << endl;
    }
    else
    {
        cout << "No triangle (3 mutually connected cities) found." << endl;
    }

    cout << endl;

    cout << "=== Longest edge ===" << endl;
    int maxWeight = 0;
    int edgeA = -1;
    int edgeB = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (matrix[i][j] > maxWeight)
            {
                maxWeight = matrix[i][j];
                edgeA = i;
                edgeB = j;
            }
        }
    }

    cout << "Longest edge: " << edgeA + 1 << " -- " << edgeB + 1;
    cout << " (weight: " << maxWeight << ")" << endl;

    return 0;
}
