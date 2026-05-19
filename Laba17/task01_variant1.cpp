#include <iostream>
#include <string>

using namespace std;

struct Student
{
    string surname;
    int groupNumber;
    int grades[4];
    double average;
};

void calcAverage(Student students[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < 4; j++)
        {
            sum += students[i].grades[j];
        }
        students[i].average = (double)sum / 4;
    }
}

void bubbleSortByAverage(Student students[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (students[j].average > students[j + 1].average)
            {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void insertionSortByGroup(Student students[], int n)
{
    for (int i = 1; i < n; i++)
    {
        Student key = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].groupNumber < key.groupNumber)
        {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = key;
    }
}

void printStudents(Student students[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". " << students[i].surname;
        cout << " | Group: " << students[i].groupNumber;
        cout << " | Grades: ";
        for (int j = 0; j < 4; j++)
        {
            cout << students[i].grades[j] << " ";
        }
        cout << "| Average: " << students[i].average << endl;
    }
}

void binarySearch(Student students[], int n, double target)
{
    int left = 0;
    int right = n - 1;
    int foundIndex = -1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (students[mid].average == target)
        {
            foundIndex = mid;
            break;
        }
        else if (students[mid].average < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (foundIndex == -1)
    {
        cout << "No student found with average: " << target << endl;
        return;
    }

    int left2 = foundIndex;
    while (left2 > 0 && students[left2 - 1].average == target)
    {
        left2--;
    }

    int right2 = foundIndex;
    while (right2 < n - 1 && students[right2 + 1].average == target)
    {
        right2++;
    }

    cout << "Students with average " << target << ":" << endl;
    for (int i = left2; i <= right2; i++)
    {
        cout << "  " << students[i].surname;
        cout << " | Group: " << students[i].groupNumber;
        cout << " | Average: " << students[i].average << endl;
    }
}

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student students[100];

    for (int i = 0; i < n; i++)
    {
        cout << endl << "Student " << i + 1 << ":" << endl;
        cout << "Enter surname: ";
        cin >> students[i].surname;
        cout << "Enter group number: ";
        cin >> students[i].groupNumber;
        cout << "Enter 4 grades: ";
        for (int j = 0; j < 4; j++)
        {
            cin >> students[i].grades[j];
        }
        students[i].average = 0;
    }

    calcAverage(students, n);

    Student copy[100];
    for (int i = 0; i < n; i++)
    {
        copy[i] = students[i];
    }

    bubbleSortByAverage(students, n);

    cout << endl << "=== Sorted by average (ascending) ===" << endl;
    printStudents(students, n);

    insertionSortByGroup(copy, n);

    cout << endl << "=== Sorted by group number (descending) ===" << endl;
    printStudents(copy, n);

    double searchAvg;
    cout << endl << "Enter average to search: ";
    cin >> searchAvg;

    cout << endl << "=== Binary search result ===" << endl;
    binarySearch(students, n, searchAvg);

    return 0;
}
