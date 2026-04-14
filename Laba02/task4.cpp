#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    int matrix[10][10];
    cout << "Enter elements of matrix:" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    for (int i = 0; i < n; i++)
        matrix[i][i] = 0;

    cout << "Matrix after removing the main diagonal (replaced with 0):" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }

    int maxVal = matrix[0][0];
    int maxRow = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == i)
                continue;
            if (matrix[i][j] > maxVal)
            {
                maxVal = matrix[i][j];
                maxRow = i;
            }
        }
    }

    cout << "Row with maximum element (" << maxVal << "): " << maxRow + 1 << endl;

    for (int i = maxRow; i < n - 1; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = matrix[i + 1][j];
    n--;

    cout << "Matrix after removing the row:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }

    return 0;
}
