#include <iostream>
#include <iomanip>
#include <cstdlib> 
#include <ctime>
#include <fstream>

using namespace std;

bool check_n(int n) {
    return (n > 0 && n % 4 == 0);
}

void input_array(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % 601 - 150) / 100.0f;
    }
}

float** create_matrix(float arr[], int n) {
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

void bubble_sort(float arr[], int size, bool ascending) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1])) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

float find_max(float arr[], int size) {
    float max_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

int main() {
    srand(time(NULL));
    ofstream out_file("output.txt");
    
    out_file << "-------------------------------------------------\n";
    out_file << "| " << setw(2) << "N" << " | " << setw(5) << "n" << " | " << setw(12) << "Time, sec." << " | " << setw(12) << "Space, byte" << " |\n";
    out_file << "-------------------------------------------------\n";

    int n_values[3] = {20, 100, 1000};

    for (int test = 0; test < 3; test++) {
        int n = n_values[test];
        if (!check_n(n)) continue;

        clock_t start = clock();

        float* A = new float[n];
        input_array(A, n);

        int rows = n / 4;
        float** B = create_matrix(A, n);

        for (int i = 0; i < rows; i++) {
            bubble_sort(B[i], 4, (i % 2 == 0));
        }

        float max_in_columns[4];
        for (int col = 0; col < 4; col++) {
            float* column_array = new float[rows];
            for (int row = 0; row < rows; row++) {
                column_array[row] = B[row][col];
            }
            max_in_columns[col] = find_max(column_array, rows);
            delete[] column_array;
        }

        clock_t end = clock();
        double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

        int space = (n * sizeof(float)) + (rows * sizeof(float*)) + (rows * 4 * sizeof(float)) + (4 * sizeof(float));

        out_file << "| " << setw(2) << test + 1 << " | " 
                 << setw(5) << n << " | " 
                 << setw(12) << fixed << setprecision(3) << time_spent << " | " 
                 << setw(12) << space << " |\n";
                 
        for (int i = 0; i < rows; i++) {
            delete[] B[i];
        }
        delete[] B;
        delete[] A;
    }
    
    out_file << "-------------------------------------------------\n";

    out_file.close();
    return 0;
}