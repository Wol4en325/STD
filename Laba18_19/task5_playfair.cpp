#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;

char matrix[5][5];
bool used[26];

void buildMatrix(char key[])
{
    int pos = 0;

    memset(used, false, sizeof(used));
    used['j' - 'a'] = true;

    for (int i = 0; key[i] != '\0'; i++)
    {
        char c = tolower(key[i]);

        if (isalpha(c) && !used[c - 'a'])
        {
            matrix[pos / 5][pos % 5] = c;
            used[c - 'a'] = true;
            pos++;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (!used[i])
        {
            matrix[pos / 5][pos % 5] = 'a' + i;
            pos++;
        }
    }
}

void printMatrix()
{
    cout << endl << "Playfair matrix:" << endl;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            cout << matrix[i][j] << " ";

        cout << endl;
    }
}

void findPos(char c, int &row, int &col)
{
    if (c == 'j')
        c = 'i';

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (matrix[i][j] == c)
            {
                row = i;
                col = j;
                return;
            }
        }
    }
}

void prepareText(char text[], char prepared[], int &len)
{
    len = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        char c = tolower(text[i]);

        if (c == 'j')
            c = 'i';

        if (isalpha(c))
            prepared[len++] = c;
    }

    for (int i = 0; i < len - 1; i += 2)
    {
        if (prepared[i] == prepared[i + 1])
        {
            for (int j = len; j > i + 1; j--)
                prepared[j] = prepared[j - 1];

            prepared[i + 1] = 'x';
            len++;
        }
    }

    if (len % 2 != 0)
        prepared[len++] = 'x';

    prepared[len] = '\0';
}

void encryptPlayfair(char prepared[], int len, char result[])
{
    int idx = 0;

    for (int i = 0; i < len; i += 2)
    {
        int r1, c1, r2, c2;

        findPos(prepared[i], r1, c1);
        findPos(prepared[i + 1], r2, c2);

        if (r1 == r2)
        {
            result[idx++] = matrix[r1][(c1 + 1) % 5];
            result[idx++] = matrix[r2][(c2 + 1) % 5];
        }
        else if (c1 == c2)
        {
            result[idx++] = matrix[(r1 + 1) % 5][c1];
            result[idx++] = matrix[(r2 + 1) % 5][c2];
        }
        else
        {
            result[idx++] = matrix[r1][c2];
            result[idx++] = matrix[r2][c1];
        }
    }

    result[idx] = '\0';
}

void decryptPlayfair(char prepared[], int len, char result[])
{
    int idx = 0;

    for (int i = 0; i < len; i += 2)
    {
        int r1, c1, r2, c2;

        findPos(prepared[i], r1, c1);
        findPos(prepared[i + 1], r2, c2);

        if (r1 == r2)
        {
            result[idx++] = matrix[r1][(c1 + 4) % 5];
            result[idx++] = matrix[r2][(c2 + 4) % 5];
        }
        else if (c1 == c2)
        {
            result[idx++] = matrix[(r1 + 4) % 5][c1];
            result[idx++] = matrix[(r2 + 4) % 5][c2];
        }
        else
        {
            result[idx++] = matrix[r1][c2];
            result[idx++] = matrix[r2][c1];
        }
    }

    result[idx] = '\0';
}

int main()
{
    char key[100];

    cout << "Enter key word: ";
    cin.getline(key, 100);

    buildMatrix(key);

    printMatrix();

    char text[5000];
    int choice;

    cout << endl << "Input source (1 - keyboard, 2 - file): ";
    cin >> choice;
    cin.ignore();

    if (choice == 1)
    {
        cout << "Enter text: ";
        cin.getline(text, 5000);
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
            strcat(text, " ");
        }

        file.close();
    }

    int mode;

    cout << "Mode (1 - encrypt, 2 - decrypt): ";
    cin >> mode;
    cin.ignore();

    char prepared[5000];
    char result[5000];
    int len = 0;

    cout << endl << "Original: " << text << endl;

    if (mode == 1)
    {
        prepareText(text, prepared, len);

        cout << "Prepared: " << prepared << endl;

        encryptPlayfair(prepared, len, result);

        cout << "Encrypted: " << result << endl;
    }
    else
    {
        len = strlen(text);

        for (int i = 0; i < len; i++)
            prepared[i] = tolower(text[i]);

        prepared[len] = '\0';

        decryptPlayfair(prepared, len, result);

        cout << "Decrypted: " << result << endl;
    }

    return 0;
}