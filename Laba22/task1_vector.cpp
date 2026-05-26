#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
    ifstream file("numbers.txt");
    if (!file)
    {
        cout << "Could not open file numbers.txt" << endl;
        return 1;
    }

    int n;
    cout << "Enter how many numbers to use (max 1000): ";
    cin >> n;

    vector<int> v;
    int num;
    int count = 0;
    while (file >> num && count < n)
    {
        v.push_back(num);
        count++;
    }
    file.close();

    cout << endl << "=== Original vector ===" << endl;
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;

    int third = v.size() / 3;

    sort(v.begin(), v.begin() + third, greater<int>());
    sort(v.begin() + 2 * third, v.end(), less<int>());

    cout << endl << "=== After sorting first third desc, last third asc ===" << endl;
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    cout << endl << "=== After removing consecutive duplicates ===" << endl;
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;

    vector<int> groupBig;
    vector<int> groupSmall;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] >= 10)
            groupBig.push_back(v[i]);
        else
            groupSmall.push_back(v[i]);
    }

    cout << endl << "=== Group >= 10 ===" << endl;
    for (int i = 0; i < groupBig.size(); i++) cout << groupBig[i] << " ";
    cout << endl;

    cout << endl << "=== Group < 10 ===" << endl;
    for (int i = 0; i < groupSmall.size(); i++) cout << groupSmall[i] << " ";
    cout << endl;

    for (int i = 0; i < groupSmall.size(); i++)
        groupSmall[i] += 100;

    cout << endl << "=== Group < 10 after adding 100 ===" << endl;
    for (int i = 0; i < groupSmall.size(); i++) cout << groupSmall[i] << " ";
    cout << endl;

    v.clear();
    for (int i = 0; i < groupBig.size(); i++) v.push_back(groupBig[i]);
    for (int i = 0; i < groupSmall.size(); i++) v.push_back(groupSmall[i]);

    int maxVal = *max_element(v.begin(), v.end());
    int minVal = *min_element(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > 100) v[i] = maxVal;
        if (v[i] < -100) v[i] = minVal;
    }

    cout << endl << "=== After replacing out-of-range values ===" << endl;
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;

    vector<int> result;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] < -5 || v[i] > 5)
            result.push_back(v[i]);
    }
    v = result;

    cout << endl << "=== After removing numbers in [-5; 5] ===" << endl;
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;

    return 0;
}
