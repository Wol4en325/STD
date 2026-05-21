#include <iostream>
#include <cstring>

using namespace std;

const int ROWS = 3;
const int COLS = 3;

int cost[ROWS][COLS] = {
    {8, 7, 2},
    {1, 4, 3},
    {5, 1, 6}
};

int supply[ROWS] = {1500, 1900, 1600};
int demand[COLS] = {1800, 1200, 2000};

void printPlan(int plan[ROWS][COLS], int totalCost)
{
    cout << "|      | M1   | M2   | M3   |" << endl;
    cout << "|------|------|------|------|" << endl;
    for (int i = 0; i < ROWS; i++)
    {
        cout << "| C" << i + 1 << "   |";
        for (int j = 0; j < COLS; j++)
            cout << " " << plan[i][j] << "\t|";
        cout << endl;
    }
    cout << "Total cost: " << totalCost << " units" << endl;
}

int calcCost(int plan[ROWS][COLS])
{
    int total = 0;
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            total += plan[i][j] * cost[i][j];
    return total;
}

void northwestCorner()
{
    cout << "=== Northwest Corner Method ===" << endl;

    int plan[ROWS][COLS];
    memset(plan, 0, sizeof(plan));

    int s[ROWS], d[COLS];
    for (int i = 0; i < ROWS; i++) s[i] = supply[i];
    for (int j = 0; j < COLS; j++) d[j] = demand[j];

    int i = 0, j = 0;
    while (i < ROWS && j < COLS)
    {
        int amount = s[i] < d[j] ? s[i] : d[j];
        plan[i][j] = amount;
        s[i] -= amount;
        d[j] -= amount;

        if (s[i] == 0 && d[j] == 0)
        {
            i++;
            j++;
        }
        else if (s[i] == 0)
            i++;
        else
            j++;
    }

    printPlan(plan, calcCost(plan));
}

void minimumCost()
{
    cout << endl << "=== Minimum Cost Method ===" << endl;

    int plan[ROWS][COLS];
    memset(plan, 0, sizeof(plan));

    int s[ROWS], d[COLS];
    for (int i = 0; i < ROWS; i++) s[i] = supply[i];
    for (int j = 0; j < COLS; j++) d[j] = demand[j];

    bool rowDone[ROWS] = {false, false, false};
    bool colDone[COLS] = {false, false, false};

    int allocated = 0;
    int totalCells = ROWS * COLS;

    while (allocated < ROWS + COLS - 1)
    {
        int minCost = 999999;
        int minI = -1, minJ = -1;

        for (int i = 0; i < ROWS; i++)
        {
            if (rowDone[i]) continue;
            for (int j = 0; j < COLS; j++)
            {
                if (colDone[j]) continue;
                if (cost[i][j] < minCost)
                {
                    minCost = cost[i][j];
                    minI = i;
                    minJ = j;
                }
            }
        }

        if (minI == -1) break;

        int amount = s[minI] < d[minJ] ? s[minI] : d[minJ];
        plan[minI][minJ] = amount;
        s[minI] -= amount;
        d[minJ] -= amount;

        if (s[minI] == 0 && d[minJ] == 0)
        {
            rowDone[minI] = true;
            colDone[minJ] = true;
            allocated += 2;
        }
        else if (s[minI] == 0)
        {
            rowDone[minI] = true;
            allocated++;
        }
        else
        {
            colDone[minJ] = true;
            allocated++;
        }
    }

    printPlan(plan, calcCost(plan));
}

int main()
{
    cout << "Cost matrix:" << endl;
    cout << "|      | M1 | M2 | M3 | Supply |" << endl;
    cout << "|------|----|----|----|----|" << endl;
    for (int i = 0; i < ROWS; i++)
    {
        cout << "| C" << i + 1 << "   |";
        for (int j = 0; j < COLS; j++)
            cout << "  " << cost[i][j] << " |";
        cout << " " << supply[i] << "   |" << endl;
    }
    cout << "| Need | " << demand[0] << "| " << demand[1] << "| " << demand[2] << "|" << endl;
    cout << endl;

    northwestCorner();
    minimumCost();

    return 0;
}
