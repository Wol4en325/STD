#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;

void encryptCaesar(char text[], int shift)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            char base = islower(text[i]) ? 'a' : 'A';
            text[i] = (char)((text[i] - base + shift % 26 + 26) % 26 + base);
        }
    }
}

void decryptCaesar(char text[], int shift)
{
    encryptCaesar(text, -shift);
}

int findFreqShift(char text[])
{
    int freq[26] = {0};
    int total = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            freq[tolower(text[i]) - 'a']++;
            total++;
        }
    }

    int maxIdx = 0;
    for (int i = 1; i < 26; i++)
        if (freq[i] > freq[maxIdx])
            maxIdx = i;

    return (maxIdx - ('e' - 'a') + 26) % 26;
}

bool containsKeyword(char text[], char keyword[])
{
    int tLen = strlen(text);
    int kLen = strlen(keyword);

    for (int i = 0; i <= tLen - kLen; i++)
    {
        bool match = true;
        for (int j = 0; j < kLen; j++)
        {
            if (tolower(text[i + j]) != tolower(keyword[j]))
            {
                match = false;
                break;
            }
        }
        if (match)
            return true;
    }
    return false;
}

int main()
{
    char text[1000];
    int choice;

    cout << "Input source (1 - keyboard, 2 - file): ";
    cin >> choice;
    cin.ignore();

    if (choice == 1)
    {
        cout << "Enter text: ";
        cin.getline(text, 1000);
    }
    else
    {
        char filename[100];
        cout << "Enter filename: ";
        cin.getline(filename, 100);

ifstream file(filename);

if (!file)
{
    cout << "File not found." << endl;
    return 1;
}

char line[200];
text[0] = '\0';

while (file.getline(line, 200))
{
    strcat(text, line);
    strcat(text, "\n");
}

file.close();
    }

    cout << "Original text: " << text << endl;

   int shift;
cout << "Enter shift (positive = right, negative = left): ";

while (!(cin >> shift))
{
    cout << "Invalid input! Enter a NUMBER: ";

    cin.clear(); 
    cin.ignore(1000, '\n');
}
cin.ignore();

    int mode;
    cout << "Mode (1 - encrypt, 2 - decrypt by shift, 3 - decrypt by frequency): ";
    cin >> mode;
    cin.ignore();

    char result[1000];
    strcpy(result, text);

    if (mode == 1)
    {
        encryptCaesar(result, shift);
        cout << "Encrypted: " << result << endl;
    }
    else if (mode == 2)
    {
        decryptCaesar(result, shift);
        cout << "Decrypted: " << result << endl;
    }
    else if (mode == 3)
    {
        int freqShift = findFreqShift(text);
        cout << "Detected shift by frequency: " << freqShift << endl;
        decryptCaesar(result, freqShift);
        cout << "Decrypted: " << result << endl;

        char keyword[100];
        cout << "Enter keyword to search in decrypted text: ";
        cin.getline(keyword, 100);

        if (containsKeyword(result, keyword))
            cout << "Keyword \"" << keyword << "\" FOUND in decrypted text." << endl;
        else
            cout << "Keyword \"" << keyword << "\" NOT found." << endl;
    }

    return 0;
}
