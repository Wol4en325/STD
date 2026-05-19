#include <iostream>
#include <string>

using namespace std;

struct Student
{
    string surname;
    int exams[3];
    double average;
};

void calcAverage(Student students[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += students[i].exams[j];
        }
        students[i].average = (double)sum / 3;
    }
}

void printStudent(int index, Student &s)
{
    cout << index << ". " << s.surname;
    cout << " | Exams: ";
    for (int j = 0; j < 3; j++)
    {
        cout << s.exams[j] << " ";
    }
    cout << "| Average: " << s.average << endl;
}

void findMaxAverage(Student students[], int n)
{
    double maxAvg = students[0].average;

    for (int i = 1; i < n; i++)
    {
        if (students[i].average > maxAvg)
        {
            maxAvg = students[i].average;
        }
    }

    cout << "Max average: " << maxAvg << endl;

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (students[i].average == maxAvg)
        {
            count++;
        }
    }

    cout << "Number of students with max average: " << count << endl;
    cout << "Their positions:" << endl;

    for (int i = 0; i < n; i++)
    {
        if (students[i].average == maxAvg)
        {
            printStudent(i + 1, students[i]);
        }
    }
}

void bubbleSort(Student students[], int n)
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
        cout << " | Average: " << students[i].average << endl;
    }
}

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student students[100];
    Student sorted[100];

    for (int i = 0; i < n; i++)
    {
        cout << endl << "Student " << i + 1 << ":" << endl;
        cout << "Enter surname: ";
        cin >> students[i].surname;
        cout << "Enter 3 exam scores: ";
        for (int j = 0; j < 3; j++)
        {
            cin >> students[i].exams[j];
        }
        students[i].average = 0;
    }

    calcAverage(students, n);

    cout << endl << "=== All students ===" << endl;
    for (int i = 0; i < n; i++)
    {
        printStudent(i + 1, students[i]);
    }

    cout << endl << "=== Students with max average (linear search) ===" << endl;
    findMaxAverage(students, n);

    for (int i = 0; i < n; i++)
    {
        sorted[i] = students[i];
    }

    bubbleSort(sorted, n);

    double target;
    cout << endl << "Enter average to search: ";
    cin >> target;

    cout << endl << "=== Binary search result ===" << endl;
    binarySearch(sorted, n, target);

    return 0;
}
