#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;

const char POLYBIUS[5][5] = {
    {'a', 'b', 'c', 'd', 'e'},
    {'f', 'g', 'h', 'i', 'k'},
    {'l', 'm', 'n', 'o', 'p'},
    {'q', 'r', 's', 't', 'u'},
    {'v', 'w', 'x', 'y', 'z'}
};

void printSquare()
{
    cout << endl << "Polybius square:" << endl;
    cout << "  1 2 3 4 5" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " ";
        for (int j = 0; j < 5; j++)
            cout << POLYBIUS[i][j] << " ";
        cout << endl;
    }
}

void encryptPolybius(char text[], char result[], int &resultLen)
{
    resultLen = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        char c = tolower(text[i]);
        if (c == 'j') c = 'i';

        if (isalpha(c))
        {
            for (int row = 0; row < 5; row++)
            {
                for (int col = 0; col < 5; col++)
                {
                    if (POLYBIUS[row][col] == c)
                    {
                        result[resultLen++] = '1' + row;
                        result[resultLen++] = '1' + col;
                        result[resultLen++] = ' ';
                    }
                }
            }
        }
        else if (text[i] == ' ')
        {
            result[resultLen++] = '/';
            result[resultLen++] = ' ';
        }
    }
    result[resultLen] = '\0';
}

void decryptPolybius(char text[], char result[], int &resultLen)
{
    resultLen = 0;
    int i = 0;

    while (text[i] != '\0')
    {
        if (text[i] == '/')
        {
            result[resultLen++] = ' ';
            i++;
            if (text[i] == ' ') i++;
        }
        else if (text[i] >= '1' && text[i] <= '5' && text[i + 1] >= '1' && text[i + 1] <= '5')
        {
            int row = text[i] - '1';
            int col = text[i + 1] - '1';
            result[resultLen++] = POLYBIUS[row][col];
            i += 2;
            if (text[i] == ' ') i++;
        }
        else
        {
            i++;
        }
    }
    result[resultLen] = '\0';
}

int main()
{
    printSquare();

    char text[1000];
    int choice;

    cout << endl << "Input source (1 - keyboard, 2 - file): ";
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

    int mode;
    cout << "Mode (1 - encrypt, 2 - decrypt): ";
    cin >> mode;

    char result[5000];
    int resultLen = 0;

    cout << "Original: " << text << endl;

    if (mode == 1)
    {
        encryptPolybius(text, result, resultLen);
        cout << "Encrypted: " << result << endl;
    }
    else
    {
        decryptPolybius(text, result, resultLen);
        cout << "Decrypted: " << result << endl;
    }

    return 0;
}
