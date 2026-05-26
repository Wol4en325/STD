#include <iostream>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int countUnique(list<int> lst)
{
    lst.sort();
    lst.unique();
    return lst.size();
}

int main()
{
    srand(time(0));

    list<int> list1;
    cout << "Enter 10 integers:" << endl;
    for (int i = 0; i < 10; i++)
    {
        int x;
        cin >> x;
        list1.push_back(x);
    }

    cout << endl << "=== List 1 ===" << endl;
    for (list<int>::iterator it = list1.begin(); it != list1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    list<int> list2;
    int prev = 0;
    for (int i = 0; i < 10; i++)
    {
        prev += rand() % 10 + 1;
        list2.push_back(prev);
    }

    cout << endl << "=== List 2 (random ascending) ===" << endl;
    for (list<int>::iterator it = list2.begin(); it != list2.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    list1.sort();
    list2.sort();
    list1.merge(list2);
    list1.sort(greater<int>());

    cout << endl << "=== Merged list (descending) ===" << endl;
    for (list<int>::iterator it = list1.begin(); it != list1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    int unique = countUnique(list1);
    cout << endl << "Number of unique elements: " << unique << endl;

    return 0;
}
