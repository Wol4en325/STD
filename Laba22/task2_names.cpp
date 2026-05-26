#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

bool isVowel(char c)
{
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
    ifstream file("names.txt");
    if (!file)
    {
        cout << "Could not open file names.txt" << endl;
        return 1;
    }

    vector<string> names;
    string word;
    while (file >> word)
    {
        names.push_back(word);
    }
    file.close();

    cout << "=== Names from file ===" << endl;
    for (int i = 0; i < names.size(); i++) cout << names[i] << " ";
    cout << endl;

    cout << endl << "Enter name to search: ";
    string search;
    cin >> search;

    int cnt = count(names.begin(), names.end(), search);
    cout << "Name \"" << search << "\" found " << cnt << " time(s)." << endl;

    for (int i = 0; i < names.size(); i++)
        for (int j = 0; j < names[i].size(); j++)
            names[i][j] = toupper(names[i][j]);

    cout << endl << "=== All uppercase ===" << endl;
    for (int i = 0; i < names.size(); i++) cout << names[i] << " ";
    cout << endl;

    for (int i = 0; i < names.size(); i++)
        for (int j = 0; j < names[i].size(); j++)
            names[i][j] = tolower(names[i][j]);

    cout << endl << "=== All lowercase ===" << endl;
    for (int i = 0; i < names.size(); i++) cout << names[i] << " ";
    cout << endl;

    stable_partition(names.begin(), names.end(), [](const string &s)
    {
        char c = tolower(s[0]);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    });

    cout << endl << "=== Vowel-first, then consonant (order preserved) ===" << endl;
    for (int i = 0; i < names.size(); i++) cout << names[i] << " ";
    cout << endl;

    return 0;
}
