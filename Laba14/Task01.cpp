#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main() {
    array<int, 10> a;

    cout << "Enter 10 grades:" << endl;
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }

    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += a[i];
    }

    double avg = sum / 10.0;

    int minVal = *min_element(a.begin(), a.end());
    int maxVal = *max_element(a.begin(), a.end());

    int count = 0;
    for (int i = 0; i < 10; i++) {
        if (a[i] > avg) count++;
    }

    sort(a.begin(), a.end());

    cout << "Average: " << avg << endl;
    cout << "Min: " << minVal << endl;
    cout << "Max: " << maxVal << endl;
    cout << "Above average: " << count << endl;

    cout << "Sorted: ";
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }

    return 0;
}