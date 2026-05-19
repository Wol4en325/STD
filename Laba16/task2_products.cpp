#include <iostream>
#include <string>

using namespace std;

struct Product
{
    string name;
    double proteins;
    double fats;
    double carbs;
    double calories;
};

void calcCalories(Product products[], int n)
{
    for (int i = 0; i < n; i++)
    {
        products[i].calories = 4 * products[i].proteins
                             + 9 * products[i].fats
                             + 4 * products[i].carbs;
    }
}

void printProduct(int index, Product &p)
{
    cout << index << ". " << p.name;
    cout << " | Proteins: " << p.proteins;
    cout << " | Fats: " << p.fats;
    cout << " | Carbs: " << p.carbs;
    cout << " | Calories: " << p.calories << endl;
}

void findMaxCalories(Product products[], int n)
{
    double maxCal = products[0].calories;

    for (int i = 1; i < n; i++)
    {
        if (products[i].calories > maxCal)
        {
            maxCal = products[i].calories;
        }
    }

    cout << "Max calorie value: " << maxCal << endl;

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (products[i].calories == maxCal)
        {
            count++;
        }
    }

    cout << "Number of products with max calories: " << count << endl;
    cout << "Their positions:" << endl;

    for (int i = 0; i < n; i++)
    {
        if (products[i].calories == maxCal)
        {
            printProduct(i + 1, products[i]);
        }
    }
}

void searchByRange(Product products[], int n)
{
    double a, b;
    cout << "Enter range A: ";
    cin >> a;
    cout << "Enter range B: ";
    cin >> b;

    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (products[i].calories >= a && products[i].calories <= b)
        {
            printProduct(i + 1, products[i]);
            found = true;
        }
    }

    if (!found)
    {
        cout << "No products found in range [" << a << "; " << b << "]." << endl;
    }
}

int main()
{
    int n;
    cout << "Enter number of products: ";
    cin >> n;

    Product products[100];

    for (int i = 0; i < n; i++)
    {
        cout << endl << "Product " << i + 1 << ":" << endl;
        cout << "Enter name: ";
        cin >> products[i].name;
        cout << "Enter proteins (g): ";
        cin >> products[i].proteins;
        cout << "Enter fats (g): ";
        cin >> products[i].fats;
        cout << "Enter carbs (g): ";
        cin >> products[i].carbs;
        products[i].calories = 0;
    }

    calcCalories(products, n);

    cout << endl << "=== All products ===" << endl;
    for (int i = 0; i < n; i++)
    {
        printProduct(i + 1, products[i]);
    }

    cout << endl << "=== Products with max calories ===" << endl;
    findMaxCalories(products, n);

    cout << endl << "=== Search by calorie range ===" << endl;
    searchByRange(products, n);

    return 0;
}
