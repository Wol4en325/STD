#include <iostream>

using namespace std;

struct Worker
{
    char name[50];
    char position[50];
    int startYear;
    double salary;
};

int experience(Worker w)
{
    return 2025 - w.startYear;
}

double salaryWithTax(Worker w)
{
    return w.salary - w.salary * 0.33;
}

void printWorker(Worker w)
{
    cout << "Name: " << w.name << endl;
    cout << "Position: " << w.position << endl;
    cout << "Start year: " << w.startYear << endl;
    cout << "Salary (before tax): " << w.salary << endl;
    cout << "Work experience: " << experience(w) << " years" << endl;
    cout << "Salary (after 33% tax): " << salaryWithTax(w) << endl;
    cout << "----------------------------" << endl;
}

int main()
{
    int n;
    cout << "Enter number of workers: ";
    cin >> n;
    cin.ignore();

    Worker workers[100];

    for (int i = 0; i < n; i++)
    {
        cout << "\nWorker " << i + 1 << ":" << endl;

        cout << "Enter name: ";
        cin.getline(workers[i].name, 50);

        cout << "Enter position: ";
        cin.getline(workers[i].position, 50);

        cout << "Enter start year: ";
        cin >> workers[i].startYear;

        cout << "Enter salary: ";
        cin >> workers[i].salary;
        cin.ignore();
    }

    cout << "\n========== Workers information ==========" << endl;
    for (int i = 0; i < n; i++)
        printWorker(workers[i]);

    return 0;
}