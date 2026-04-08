#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

bool checkN(int n) {
    return (n > 0 && n % 4 == 0);
}

void inputArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % 601 - 150) / 100.0f;
    }
}

void printArray(float arr[], int n) {
    cout << "Array A:" << endl;
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(2) << arr[i] << " ";
        if ((i + 1) % 10 == 0) cout << endl;
    }
    cout << endl;
}

float** createMatrix(float arr[], int n) {
    int rows = n / 4;
    float** matrix = new float*[rows];

    int k = 0;
    for (int i = 0; i < rows; i++) {
        matrix[i] = new float[4];
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = arr[k++];
        }
    }

    return matrix;
}

void bubbleSort(float arr[], int size, bool ascending) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if ((ascending && arr[j] > arr[j + 1]) ||
                (!ascending && arr[j] < arr[j + 1])) {

                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

float findMax(float arr[], int size) {
    float maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main() {
    srand(time(0));

    ofstream outFile("output.txt");

    outFile << "-------------------------------------------------" << endl;
    outFile << "| " << setw(2) << "N" << " | "
            << setw(5) << "n" << " | "
            << setw(12) << "Time, sec." << " | "
            << setw(12) << "Space, byte" << " |" << endl;
    outFile << "-------------------------------------------------" << endl;

    int nValues[3] = {20, 100, 1000};

    for (int test = 0; test < 3; test++) {
        int n = nValues[test];

        if (!checkN(n)) continue;

        clock_t start = clock();

        float* A = new float[n];
        inputArray(A, n);

        printArray(A, n); // вивід масиву

        int rows = n / 4;
        float** B = createMatrix(A, n);

        for (int i = 0; i < rows; i++) {
            if (i % 2 == 0)
                bubbleSort(B[i], 4, true);
            else
                bubbleSort(B[i], 4, false);
        }

        float maxInColumns[4];

        for (int col = 0; col < 4; col++) {
            float* temp = new float[rows];

            for (int row = 0; row < rows; row++) {
                temp[row] = B[row][col];
            }

            maxInColumns[col] = findMax(temp, rows);
            delete[] temp;
        }

        clock_t end = clock();
        double timeSpent = (double)(end - start) / CLOCKS_PER_SEC;

        int space = (n * sizeof(float)) +
                    (rows * sizeof(float*)) +
                    (rows * 4 * sizeof(float)) +
                    (4 * sizeof(float));

        outFile << "| " << setw(2) << test + 1 << " | "
                << setw(5) << n << " | "
                << setw(12) << fixed << setprecision(3) << timeSpent << " | "
                << setw(12) << space << " |" << endl;

        for (int i = 0; i < rows; i++) {
            delete[] B[i];
        }
        delete[] B;
        delete[] A;
    }

    outFile << "-------------------------------------------------" << endl;

    outFile.close();

    return 0;
}