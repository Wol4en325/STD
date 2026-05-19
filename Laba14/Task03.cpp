#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    deque<string> q;
    int choice;
    string s;

    while (true) {
        cout << "1.Normal request" << endl;
        cout << "2.Urgent request" << endl;
        cout << "3.Process" << endl;
        cout << "4.Size" << endl;
        cout << "0.Exit" << endl;

        cin >> choice;
        cin.ignore(1000, '\n');

        if (choice == 1) {
            cout << "Enter: ";
            getline(cin, s);
            q.push_back(s);
        }
        else if (choice == 2) {
            cout << "Enter: ";
            getline(cin, s);
            q.push_front(s);
        }
        else if (choice == 3) {
            if (!q.empty()) {
                cout << "Processing: " << q.front() << endl;
                q.pop_front();
            } else {
                cout << "Queue is empty" << endl;
            }
        }
        else if (choice == 4) {
            cout << "Size: " << q.size() << endl;
        }
        else if (choice == 0) break;
    }

    return 0;
}