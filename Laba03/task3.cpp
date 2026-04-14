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
    cout << "\nPayment " << number << ":" << endl;
    p.id = number;

    cout << "Payment type (1 - Cash, 2 - Card, 3 - Bank transfer): ";
    int t;
    cin >> t;
    cin.ignore();
    p.type = (PaymentType)t;

    if (p.type == CASH)
    {
        cout << "Note (cash): ";
        cin.getline(p.details.cashNote, 50);
    }
    else if (p.type == CARD)
    {
        cout << "Card number: ";
        cin.getline(p.details.cardNumber, 20);
    }
    else if (p.type == BANK_TRANSFER)
    {
        cout << "IBAN code: ";
        cin.getline(p.details.ibanCode, 30);
    }
}

void printPayment(Payment p)
{
    cout << "\nPayment ID: " << p.id << endl;

    if (p.type == CASH)
    {
        cout << "Type: Cash" << endl;
        cout << "Note: " << p.details.cashNote << endl;
    }
    else if (p.type == CARD)
    {
        cout << "Type: Card" << endl;
        cout << "Card number: " << p.details.cardNumber << endl;
    }
    else if (p.type == BANK_TRANSFER)
    {
        cout << "Type: Bank transfer" << endl;
        cout << "IBAN: " << p.details.ibanCode << endl;
    }

    cout << "----------------------------" << endl;
}

int main()
{
    int n;
    cout << "Enter number of payments: ";
    cin >> n;
    cin.ignore();

    Payment payments[100];

    for (int i = 0; i < n; i++)
        inputPayment(payments[i], i + 1);

    cout << "\n========== All payments ==========" << endl;
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

    cout << "========== Statistics ==========" << endl;
    cout << "Cash: " << cashCount << endl;
    cout << "Card: " << cardCount << endl;
    cout << "Bank transfer: " << transferCount << endl;

    return 0;
}