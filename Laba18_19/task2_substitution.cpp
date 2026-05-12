#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;

const char ALPHABET[] = "abcdefghijklmnopqrstuvwxyz";
const char KEY[]      = "qwertyuiopasdfghjklzxcvbnm";

char encryptChar(char c)
{
    if (!isalpha(c))
        return c;

    bool upper = isupper(c);
    char lower = tolower(c);

    for (int i = 0; i < 26; i++)
    {
        if (ALPHABET[i] == lower)
            return upper ? toupper(KEY[i]) : KEY[i];
    }
    return c;
}

char decryptChar(char c)
{
    if (!isalpha(c))
        return c;

    bool upper = isupper(c);
    char lower = tolower(c);

    for (int i = 0; i < 26; i++)
    {
        if (KEY[i] == lower)
            return upper ? toupper(ALPHABET[i]) : ALPHABET[i];
    }
    return c;
}

void encryptText(char text[], char result[])
{
    for (int i = 0; text[i] != '\0'; i++)
        result[i] = encryptChar(text[i]);
    result[strlen(text)] = '\0';
}

void decryptText(char text[], char result[])
{
    for (int i = 0; text[i] != '\0'; i++)
        result[i] = decryptChar(text[i]);
    result[strlen(text)] = '\0';
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

    cout << "Substitution key: " << KEY << endl;
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

    int mode;
    cout << "Mode (1 - encrypt, 2 - decrypt): ";
    cin >> mode;
    cin.ignore();

    char result[1000];

    if (mode == 1)
    {
        encryptText(text, result);
        cout << "Encrypted: " << result << endl;
    }
    else
    {
        decryptText(text, result);
        cout << "Decrypted: " << result << endl;

        char keyword[100];
        cout << "Enter keyword to search: ";
        cin.getline(keyword, 100);

        if (containsKeyword(result, keyword))
            cout << "Keyword \"" << keyword << "\" FOUND." << endl;
        else
            cout << "Keyword \"" << keyword << "\" NOT found." << endl;
    }

    return 0;
}
