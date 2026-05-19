#include <iostream>
#include <string>

using namespace std;

struct TV
{
    string brand;
    int screenSize;
    double price;
};

void printTV(int index, TV &t)
{
    cout << index << ". Brand: " << t.brand;
    cout << " | Screen: " << t.screenSize << " inches";
    cout << " | Price: " << t.price << " UAH" << endl;
}

void sortTVs(TV tvs[], int n)
{
    for (int i = 1; i < n; i++)
    {
        TV key = tvs[i];
        int j = i - 1;

        while (j >= 0 && tvs[j].screenSize > key.screenSize)
        {
            tvs[j + 1] = tvs[j];
            j--;
        }
        tvs[j + 1] = key;
    }

    int start = 0;
    while (start < n)
    {
        int end = start;
        while (end < n && tvs[end].screenSize == tvs[start].screenSize)
        {
            end++;
        }

        int i = start + 1;
        while (i < end)
        {
            if (i == start || tvs[i].price <= tvs[i - 1].price)
            {
                i++;
            }
            else
            {
                TV temp = tvs[i];
                tvs[i] = tvs[i - 1];
                tvs[i - 1] = temp;
                i--;
            }
        }

        start = end;
    }
}

int main()
{
    int n;
    cout << "Enter number of TVs: ";
    cin >> n;

    TV tvs[100];

    for (int i = 0; i < n; i++)
    {
        cout << endl << "TV " << i + 1 << ":" << endl;
        cout << "Enter brand: ";
        cin >> tvs[i].brand;
        cout << "Enter screen size (32, 45 or 60): ";
        cin >> tvs[i].screenSize;
        cout << "Enter price (UAH): ";
        cin >> tvs[i].price;
    }

    cout << endl << "=== Before sorting ===" << endl;
    for (int i = 0; i < n; i++)
    {
        printTV(i + 1, tvs[i]);
    }

    sortTVs(tvs, n);

    cout << endl << "=== After sorting (screen size asc, price desc within group) ===" << endl;
    for (int i = 0; i < n; i++)
    {
        printTV(i + 1, tvs[i]);
    }

    return 0;
}
