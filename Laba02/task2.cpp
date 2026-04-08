#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool isUnique(int arr[], int count, int value)
{
    for (int i = 0; i < count; i++)
    {
        if (arr[i] == value)
            return false;
    }
    return true;
}

void removeElement(int arr[], int &n, int index)
{
    for (int i = index; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
}

int main()
{
    srand(time(0));

    int n;
    cout << "Введіть розмір масиву: ";
    cin >> n;

    int A[100];
    int count = 0;

    while (count < n)
    {
        int value = rand() % 100 + 1;
        if (isUnique(A, count, value))
        {
            A[count] = value;
            count++;
        }
    }

    cout << "Масив: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    int X;
    cout << "Введіть значення X: ";
    cin >> X;

    int i = 0;
    int removedCount = 0;

    while (i < n)
    {
        if (A[i] <= X)
        {
            removeElement(A, n, i);
            removedCount++;
        }
        else
        {
            i++;
        }
    }

    for (int j = 0; j < removedCount; j++)
    {
        A[n] = 0;
        n++;
    }

    cout << "Результат: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    cout << "Просторова складність: O(n), де n = " << n << endl;

    return 0;
}
