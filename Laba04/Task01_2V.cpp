#include <iostream>
#include <cstring>

using namespace std;

struct Applicant
{
    char name[50];
    char gender[10];
    char specialty[50];
    int exams[3];
};

double avgScore(Applicant a)
{
    return (a.exams[0] + a.exams[1] + a.exams[2]) / 3.0;
}

bool isVowel(char c)
{
    char vowels[] = "aeiouyAEIOUY";
    for (int i = 0; vowels[i] != '\0'; i++)
    {
        if (c == vowels[i])
            return true;
    }
    return false;
}

int countVowels(char str[])
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isVowel(str[i]))
            count++;
    }
    return count;
}

void printApplicant(Applicant a)
{
    cout << "Name: " << a.name << endl;
    cout << "Gender: " << a.gender << endl;
    cout << "Specialty: " << a.specialty << endl;
    cout << "Scores: " << a.exams[0] << " " << a.exams[1] << " " << a.exams[2] << endl;
    cout << "Average score: " << avgScore(a) << endl;
    cout << "----------------------------" << endl;
}

void showFewVowels(Applicant arr[], int n)
{
    cout << endl << "=== Applicants with no more than 3 vowels in name ===" << endl;
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (countVowels(arr[i].name) <= 3)
        {
            printApplicant(arr[i]);
            found = true;
        }
    }
    if (!found)
        cout << "No such applicants." << endl;
}

void showBelowPassingScore(Applicant arr[], int n, double passing)
{
    cout << endl << "=== Applicants with score below passing (" << passing << ") ===" << endl;
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (avgScore(arr[i]) < passing)
        {
            cout << "Name: " << arr[i].name << endl;
            cout << "Specialty: " << arr[i].specialty << endl;
            cout << "----------------------------" << endl;
            found = true;
        }
    }
    if (!found)
        cout << "No such applicants." << endl;
}

void sortByName(Applicant arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(arr[j].name, arr[j + 1].name) > 0)
            {
                Applicant temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void deleteIfAvgFive(Applicant arr[], int &n)
{
    int i = 0;
    while (i < n)
    {
        if (avgScore(arr[i]) == 5.0)
        {
            for (int j = i; j < n - 1; j++)
                arr[j] = arr[j + 1];
            n--;
        }
        else
        {
            i++;
        }
    }
}

void printAll(Applicant arr[], int n)
{
    for (int i = 0; i < n; i++)
        printApplicant(arr[i]);
}

int main()
{
    int n;
    cout << "Enter number of applicants: ";
    cin >> n;
    cin.ignore();

    Applicant arr[100];

    for (int i = 0; i < n; i++)
    {
        cout << endl << "Applicant " << i + 1 << ":" << endl;

        cout << "Enter name: ";
        cin.getline(arr[i].name, 50);

        cout << "Enter gender (male/female): ";
        cin.getline(arr[i].gender, 10);

        cout << "Enter specialty: ";
        cin.getline(arr[i].specialty, 50);

        cout << "Enter 3 exam scores: ";
        cin >> arr[i].exams[0] >> arr[i].exams[1] >> arr[i].exams[2];
        cin.ignore();
    }

    cout << endl << "========== All applicants ==========" << endl;
    printAll(arr, n);

    showFewVowels(arr, n);

    double passing;
    cout << endl << "Enter passing score: ";
    cin >> passing;
    showBelowPassingScore(arr, n, passing);

    sortByName(arr, n);
    cout << endl << "========== Sorted by name ==========" << endl;
    printAll(arr, n);

    deleteIfAvgFive(arr, n);
    cout << endl << "========== After deleting avg = 5 ==========" << endl;
    if (n == 0)
        cout << "Array is empty." << endl;
    else
        printAll(arr, n);

    return 0;
}