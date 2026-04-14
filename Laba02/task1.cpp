#include <iostream>
#include <ctime>

using namespace std;

void bubbleSort(int arr[], int n, bool ascending)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            bool needSwap = false;

            if (ascending && arr[j] > arr[j + 1])
                needSwap = true;
            if (!ascending && arr[j] < arr[j + 1])
                needSwap = true;

            if (needSwap)
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int A[100];
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    int even[100], odd[100];
    int evenCount = 0, oddCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (A[i] % 2 == 0)
        {
            even[evenCount] = A[i];
            evenCount++;
        }
        else
        {
            odd[oddCount] = A[i];
            oddCount++;
        }
    }

    clock_t startAsc = clock();
    bubbleSort(even, evenCount, true);
    clock_t endAsc = clock();

    clock_t startDesc = clock();
    bubbleSort(odd, oddCount, false);
    clock_t endDesc = clock();

    int index = 0;
    for (int i = 0; i < evenCount; i++)
    {
        A[index] = even[i];
        index++;
    }
    for (int i = 0; i < oddCount; i++)
    {
        A[index] = odd[i];
        index++;
    }

    cout << "Result: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    double timeAsc = (double)(endAsc - startAsc) / CLOCKS_PER_SEC;
    double timeDesc = (double)(endDesc - startDesc) / CLOCKS_PER_SEC;

    cout << "Time for ascending sort: " << timeAsc << " sec" << endl;
    cout << "Time for descending sort: " << timeDesc << " sec" << endl;

    return 0;
}
