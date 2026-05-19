#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    multimap<string, string> book;
    int choice;
    string name, number;

    while (true) {
        cout << "1.Add" << endl;
        cout << "2.Show numbers" << endl;
        cout << "3.Delete" << endl;
        cout << "4.Show all" << endl;
        cout << "0.Exit" << endl;

        cin >> choice;
        cin.ignore(1000, '\n');

        if (choice == 1) {
            cout << "Name: ";
            getline(cin, name);
            cout << "Phone: ";
            getline(cin, number);
            book.insert({name, number});
        }
        else if (choice == 2) {
            cout << "Name: ";
            getline(cin, name);

            auto range = book.equal_range(name);

            if (range.first == range.second) {
                cout << "No numbers" << endl;
            } else {
                for (auto it = range.first; it != range.second; ++it) {
                    cout << it->second << endl;
                }
            }
        }
        else if (choice == 3) {
            cout << "Name: ";
            getline(cin, name);
            book.erase(name);
        }
        else if (choice == 4) {
            for (auto x : book) {
                cout << x.first << " : " << x.second << endl;
            }
        }
        else if (choice == 0) break;
    }

    return 0;
}