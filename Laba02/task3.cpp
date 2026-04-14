#include <iostream>

using namespace std;

void printMatrix(int matrix[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}

void swapRows(int matrix[5][5], int row1, int row2)
{
    for (int j = 0; j < 5; j++)
    {
        int temp = matrix[row1][j];
        matrix[row1][j] = matrix[row2][j];
        matrix[row2][j] = temp;
    }
}

void swapCols(int matrix[5][5], int col1, int col2)
{
    for (int i = 0; i < 5; i++)
    {
        int temp = matrix[i][col1];
        matrix[i][col1] = matrix[i][col2];
        matrix[i][col2] = temp;
    }
}

int main()
{
    int matrix[5][5];
    int iterationCount = 0;

    cout << "Enter elements of 5x5 matrix:" << endl;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> matrix[i][j];

    cout << "Initial matrix:" << endl;
    printMatrix(matrix);

    int maxRow = 0, maxCol = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (matrix[i][j] > matrix[maxRow][maxCol])
            {
                maxRow = i;
                maxCol = j;
            }
        }
    }

    if (maxRow != 0)
    {
        swapRows(matrix, 0, maxRow);
        iterationCount++;
        cout << "After swapping rows (iteration " << iterationCount << "):" << endl;
        printMatrix(matrix);
    }

    if (maxCol != 0)
    {
        swapCols(matrix, 0, maxCol);
        iterationCount++;
        cout << "After swapping columns (iteration " << iterationCount << "):" << endl;
        printMatrix(matrix);
    }

    cout << "Maximum element is now in the top-left corner." << endl;
    cout << "Time complexity of the algorithm: O(n^2)" << endl;

    return 0;
}
