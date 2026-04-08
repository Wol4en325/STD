#include <iostream>

using namespace std;

enum Faculty
{
    IT = 1,
    ECONOMICS,
    LAW,
    MANAGEMENT
};

struct Student
{
    char name[50];
    int course;
    double avgGrade;
    Faculty faculty;
};

void printFacultyName(Faculty f)
{
    if (f == IT)
        cout << "Information Technology";
    else if (f == ECONOMICS)
        cout << "Economics";
    else if (f == LAW)
        cout << "Law";
    else if (f == MANAGEMENT)
        cout << "Management";
    else
        cout << "Unknown";
}

void printStudent(Student s)
{
    cout << "Name: " << s.name << endl;
    cout << "Course: " << s.course << endl;
    cout << "Average Grade: " << s.avgGrade << endl;
    cout << "Faculty: ";
    printFacultyName(s.faculty);
    cout << endl;
    cout << "----------------------------" << endl;
}

int main()
{
    int n;
    cout << "Enter number of students: ";
    if (!(cin >> n) || n <= 0) return 0;
    cin.ignore();

    Student students[100];

    for (int i = 0; i < n; i++)
    {
        cout << "\nStudent " << i + 1 << ":" << endl;

        cout << "Full Name: ";
        cin.getline(students[i].name, 50);

        cout << "Course: ";
        cin >> students[i].course;

        cout << "Average Grade: ";
        cin >> students[i].avgGrade;

        cout << "Faculty (1-IT, 2-Econ, 3-Law, 4-Mgmt): ";
        int f;
        cin >> f;
        cin.ignore();
        students[i].faculty = (Faculty)f;
    }

    cout << "\nChoose faculty to filter (1-4): ";
    int filter;
    cin >> filter;

    cout << "\n========== Filtered List ===========" << endl;
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (students[i].faculty == (Faculty)filter)
        {
            printStudent(students[i]);
            found = true;
        }
    }
    
    if (!found) {
        cout << "No students found in this faculty." << endl;
    }

    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += students[i].avgGrade;
    }

    cout << "\nGroup average grade: " << sum / n << endl;

    return 0;
}