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
    cout << "Прізвище: " << w.name << endl;
    cout << "Посада: " << w.position << endl;
    cout << "Рік вступу: " << w.startYear << endl;
    cout << "Зарплата (до податку): " << w.salary << " грн" << endl;
    cout << "Стаж роботи: " << experience(w) << " років" << endl;
    cout << "Зарплата (після податку 33%): " << salaryWithTax(w) << " грн" << endl;
    cout << "----------------------------" << endl;
}

int main()
{
    int n;
    cout << "Введіть кількість працівників: ";
    cin >> n;
    cin.ignore();

    Worker workers[100];

    for (int i = 0; i < n; i++)
    {
        cout << "\nПрацівник " << i + 1 << ":" << endl;

        cout << "Прізвище та ініціали: ";
        cin.getline(workers[i].name, 50);

        cout << "Посада: ";
        cin.getline(workers[i].position, 50);

        cout << "Рік вступу на роботу: ";
        cin >> workers[i].startYear;

        cout << "Зарплата: ";
        cin >> workers[i].salary;
        cin.ignore();
    }

    cout << "\n========== Інформація про працівників ==========" << endl;
    for (int i = 0; i < n; i++)
        printWorker(workers[i]);

    return 0;
}
