#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void fillArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100000;
    }
}

void copyArray(int src[], int dst[], int n)
{
    for (int i = 0; i < n; i++)
    {
        dst[i] = src[i];
    }
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void gnomeSort(int arr[], int n)
{
    int i = 0;
    while (i < n)
    {
        if (i == 0 || arr[i] >= arr[i - 1])
        {
            i++;
        }
        else
        {
            int temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
            i--;
        }
    }
}

double measureTime(void (*sortFunc)(int[], int), int original[], int n)
{
    int* arr = new int[n];
    copyArray(original, arr, n);

    clock_t start = clock();
    sortFunc(arr, n);
    clock_t end = clock();

    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    delete[] arr;
    return elapsed;
}

int main()
{
    srand(time(0));

    int sizes[3] = {1000, 10000, 100000};

    cout << "Algorithm\t\tn=1000\t\tn=10000\t\tn=100000" << endl;
    cout << "----------------------------------------------------------------" << endl;

    double bubbleTimes[3];
    double insertionTimes[3];
    double selectionTimes[3];
    double gnomeTimes[3];

    for (int s = 0; s < 3; s++)
    {
        int n = sizes[s];
        int* original = new int[n];
        fillArray(original, n);

        bubbleTimes[s]    = measureTime(bubbleSort,    original, n);
        insertionTimes[s] = measureTime(insertionSort, original, n);
        selectionTimes[s] = measureTime(selectionSort, original, n);
        gnomeTimes[s]     = measureTime(gnomeSort,     original, n);

        delete[] original;
    }

    cout << "Bubble sort\t\t";
    for (int s = 0; s < 3; s++) cout << bubbleTimes[s] << "s\t\t";
    cout << endl;

    cout << "Insertion sort\t\t";
    for (int s = 0; s < 3; s++) cout << insertionTimes[s] << "s\t\t";
    cout << endl;

    cout << "Selection sort\t\t";
    for (int s = 0; s < 3; s++) cout << selectionTimes[s] << "s\t\t";
    cout << endl;

    cout << "Gnome sort\t\t";
    for (int s = 0; s < 3; s++) cout << gnomeTimes[s] << "s\t\t";
    cout << endl;

    cout << endl;

    double times[4];
    string names[4] = {"Bubble sort", "Insertion sort", "Selection sort", "Gnome sort"};

    for (int s = 0; s < 3; s++)
    {
        times[0] = bubbleTimes[s];
        times[1] = insertionTimes[s];
        times[2] = selectionTimes[s];
        times[3] = gnomeTimes[s];

        int bestIndex = 0;
        int worstIndex = 0;

        for (int i = 1; i < 4; i++)
        {
            if (times[i] < times[bestIndex]) bestIndex = i;
            if (times[i] > times[worstIndex]) worstIndex = i;
        }

        cout << "n = " << sizes[s] << ":" << endl;
        cout << "  Best:  " << names[bestIndex] << " (" << times[bestIndex] << "s)" << endl;
        cout << "  Worst: " << names[worstIndex] << " (" << times[worstIndex] << "s)" << endl;
    }

    return 0;
}
