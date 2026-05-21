#include <iostream>

using namespace std;

int main()
{
    const int POSITIONS = 8;
    const int TARGET = 380000;

    const char* names[POSITIONS] = {
        "Sanitary worker",
        "Nurse",
        "Doctor",
        "Head of pharmacy",
        "Head of department",
        "Chief doctor",
        "Head of economy",
        "Head of hospital"
    };

    int coeffA[POSITIONS] = {1, 6, 8, 9,  2, 12, 13, 3};
    int coeffB[POSITIONS] = {1, 5, 5, 5,  1,  5,  5, 1};
    int count[POSITIONS]  = {7, 10, 10, 1, 3,  1,  1, 1};

    cout << "Hospital salary calculator" << endl;
    cout << "Target fund: " << TARGET << " UAH" << endl << endl;

    int bestBase = 0;
    int bestTotal = 0;

    for (int base = 1; base <= 10000; base++)
    {
        int total = 0;
        bool valid = true;

        for (int i = 0; i < POSITIONS; i++)
        {
            double k = (double)coeffA[i] / coeffB[i];
            int salary = (int)(base * k);
            total += salary * count[i];
        }

        if (total <= TARGET && total > bestTotal)
        {
            bestTotal = total;
            bestBase = base;
        }
    }

    cout << "Best base salary (sanitary worker): " << bestBase << " UAH" << endl;
    cout << "Total fund used: " << bestTotal << " UAH" << endl;
    cout << "Difference from target: " << TARGET - bestTotal << " UAH" << endl;
    cout << endl;

    cout << "Position salaries:" << endl;
    cout << "-------------------------------------------------------------" << endl;

    int grandTotal = 0;
    for (int i = 0; i < POSITIONS; i++)
    {
        double k = (double)coeffA[i] / coeffB[i];
        int salary = (int)(bestBase * k);
        int posTotal = salary * count[i];
        grandTotal += posTotal;

        cout << names[i] << endl;
        cout << "  Coefficient: " << coeffA[i] << "/" << coeffB[i]
             << " = " << k << endl;
        cout << "  Salary: " << salary << " UAH"
             << " | Count: " << count[i]
             << " | Total: " << posTotal << " UAH" << endl;
    }

    cout << "-------------------------------------------------------------" << endl;
    cout << "Grand total: " << grandTotal << " UAH" << endl;

    return 0;
}
