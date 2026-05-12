#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

void printVigenereTable()
{
    cout << endl << "Vigenere table:" << endl;
    cout << "   ";
    for (int i = 0; i < 26; i++)
        cout << (char)('a' + i) << " ";
    cout << endl;

    for (int i = 0; i < 26; i++)
    {
        cout << (char)('a' + i) << "  ";
        for (int j = 0; j < 26; j++)
            cout << (char)(('a' + (i + j) % 26)) << " ";
        cout << endl;
    }
}

void encryptVigenere(char text[], char key[], char result[])
{
    int keyLen = strlen(key);
    int keyIdx = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            char base = islower(text[i]) ? 'a' : 'A';
            int shift = tolower(key[keyIdx % keyLen]) - 'a';
            result[i] = (char)((text[i] - base + shift) % 26 + base);
            keyIdx++;
        }
        else
        {
            result[i] = text[i];
        }
    }
    result[strlen(text)] = '\0';
}

void decryptVigenere(char text[], char key[], char result[])
{
    int keyLen = strlen(key);
    int keyIdx = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            char base = islower(text[i]) ? 'a' : 'A';
            int shift = tolower(key[keyIdx % keyLen]) - 'a';
            result[i] = (char)((text[i] - base - shift + 26) % 26 + base);
            keyIdx++;
        }
        else
        {
            result[i] = text[i];
        }
    }
    result[strlen(text)] = '\0';
}

int main()
{
    printVigenereTable();

    char text[1000];
    char key[100];
    char result[1000];

    cout << endl << "Enter text: ";
    cin.getline(text, 1000);

    cout << "Enter keyword: ";
    cin.getline(key, 100);

    int mode;
    cout << "Mode (1 - encrypt, 2 - decrypt): ";
    cin >> mode;

    cout << "Original: " << text << endl;

    if (mode == 1)
    {
        encryptVigenere(text, key, result);
        cout << "Encrypted: " << result << endl;
    }
    else
    {
        decryptVigenere(text, key, result);
        cout << "Decrypted: " << result << endl;
    }

    return 0;
}
