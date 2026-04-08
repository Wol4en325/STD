#include <iostream>

using namespace std;

enum PaymentType
{
    CASH = 1,
    CARD,
    BANK_TRANSFER
};

union PaymentDetails
{
    char cashNote[50];
    char cardNumber[20];
    char ibanCode[30];
};

struct Payment
{
    int id;
    PaymentType type;
    PaymentDetails details;
};

void inputPayment(Payment &p, int number)
{
    cout << "\nПлатіж " << number << ":" << endl;
    p.id = number;

    cout << "Тип платежу (1 - Готівка, 2 - Картка, 3 - Банківський переказ): ";
    int t;
    cin >> t;
    cin.ignore();
    p.type = (PaymentType)t;

    if (p.type == CASH)
    {
        cout << "Примітка (готівка): ";
        cin.getline(p.details.cashNote, 50);
    }
    else if (p.type == CARD)
    {
        cout << "Номер картки: ";
        cin.getline(p.details.cardNumber, 20);
    }
    else if (p.type == BANK_TRANSFER)
    {
        cout << "IBAN код: ";
        cin.getline(p.details.ibanCode, 30);
    }
}

void printPayment(Payment p)
{
    cout << "\nНомер платежу: " << p.id << endl;

    if (p.type == CASH)
    {
        cout << "Тип: Готівка" << endl;
        cout << "Примітка: " << p.details.cashNote << endl;
    }
    else if (p.type == CARD)
    {
        cout << "Тип: Картка" << endl;
        cout << "Номер картки: " << p.details.cardNumber << endl;
    }
    else if (p.type == BANK_TRANSFER)
    {
        cout << "Тип: Банківський переказ" << endl;
        cout << "IBAN: " << p.details.ibanCode << endl;
    }

    cout << "----------------------------" << endl;
}

int main()
{
    int n;
    cout << "Введіть кількість платежів: ";
    cin >> n;
    cin.ignore();

    Payment payments[100];

    for (int i = 0; i < n; i++)
        inputPayment(payments[i], i + 1);

    cout << "\n========== Всі платежі ==========" << endl;
    for (int i = 0; i < n; i++)
        printPayment(payments[i]);

    int cashCount = 0, cardCount = 0, transferCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (payments[i].type == CASH)
            cashCount++;
        else if (payments[i].type == CARD)
            cardCount++;
        else if (payments[i].type == BANK_TRANSFER)
            transferCount++;
    }

    cout << "========== Статистика ==========" << endl;
    cout << "Готівка: " << cashCount << endl;
    cout << "Картка: " << cardCount << endl;
    cout << "Банківський переказ: " << transferCount << endl;

    return 0;
}
