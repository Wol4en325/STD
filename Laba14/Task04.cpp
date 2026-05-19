#include <iostream>
#include <set>
#include <unordered_set>
#include <chrono>
#include <string>
using namespace std;

int main() {
    int N, K;
    cout << "Enter number of words: ";
    cin >> N;

    set<string> s;
    unordered_set<string> us;
    string word;

    cout << "Enter words:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> word;
        s.insert(word);
        us.insert(word);
    }

    cout << "Enter number to check: ";
    cin >> K;

    string check;

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < K; i++) {
        cin >> check;
        s.find(check);
    }
    auto end = chrono::high_resolution_clock::now();

    double t1 = chrono::duration<double, milli>(end - start).count();

    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < K; i++) {
        cin >> check;
        us.find(check);
    }
    end = chrono::high_resolution_clock::now();

    double t2 = chrono::duration<double, milli>(end - start).count();

    cout << "set time: " << t1 << " ms" << endl;
    cout << "unordered_set time: " << t2 << " ms" << endl;

    return 0;
}