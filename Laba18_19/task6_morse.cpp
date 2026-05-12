#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <windows.h>

using namespace std;

const char* LETTERS[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
    "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
    "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
    "-.--", "--.."
};

const char* DIGITS[] = {
    "-----", ".----", "..---", "...--", "....-",
    ".....", "-....", "--...", "---..", "----."
};

void textToMorse(char text[], char result[])
{
    result[0] = '\0';

    for (int i = 0; text[i] != '\0'; i++)
    {
        char c = tolower(text[i]);

        if (c >= 'a' && c <= 'z')
        {
            strcat(result, LETTERS[c - 'a']);
            strcat(result, " ");
        }
        else if (c >= '0' && c <= '9')
        {
            strcat(result, DIGITS[c - '0']);
            strcat(result, " ");
        }
        else if (c == ' ')
        {
            strcat(result, "/ ");
        }
    }
}

void morseToText(char morse[], char result[])
{
    int resultLen = 0;

    char token[20];
    int tokenLen = 0;

    int i = 0;

    while (morse[i] != '\0')
    {
        if (morse[i] == ' ')
        {
            if (tokenLen > 0)
            {
                token[tokenLen] = '\0';

                if (strcmp(token, "/") == 0)
                {
                    result[resultLen++] = ' ';
                }
                else
                {
                    bool found = false;

                    for (int j = 0; j < 26; j++)
                    {
                        if (strcmp(token, LETTERS[j]) == 0)
                        {
                            result[resultLen++] = 'a' + j;
                            found = true;
                            break;
                        }
                    }

                    if (!found)
                    {
                        for (int j = 0; j < 10; j++)
                        {
                            if (strcmp(token, DIGITS[j]) == 0)
                            {
                                result[resultLen++] = '0' + j;
                                break;
                            }
                        }
                    }
                }

                tokenLen = 0;
            }
        }
        else
        {
            token[tokenLen++] = morse[i];
        }

        i++;
    }

    if (tokenLen > 0)
    {
        token[tokenLen] = '\0';

        for (int j = 0; j < 26; j++)
        {
            if (strcmp(token, LETTERS[j]) == 0)
            {
                result[resultLen++] = 'a' + j;
                break;
            }
        }
    }

    result[resultLen] = '\0';
}

void playMorse(char morse[])
{
    for (int i = 0; morse[i] != '\0'; i++)
    {
        if (morse[i] == '.')
        {
            Beep(800, 100);
        }
        else if (morse[i] == '-')
        {
            Beep(800, 300);
        }
        else if (morse[i] == ' ')
        {
            Sleep(100);
        }
        else if (morse[i] == '/')
        {
            Sleep(300);
        }
    }
}

int main()
{
    char text[5000];

    int choice;

    cout << "Input source (1 - keyboard, 2 - file): ";
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

    cout << "Mode (1 - text to morse, 2 - morse to text): ";
    cin >> mode;
    cin.ignore();

    if (mode == 1)
    {
        char morse[10000];

        textToMorse(text, morse);

        cout << endl << "Original: " << text << endl;
        cout << "Morse: " << morse << endl;

        ofstream outFile("morse_output.txt");

        outFile << morse << endl;

        outFile.close();

        cout << "Saved to morse_output.txt" << endl;

        int playChoice;

        cout << "Play sound? (1 - yes, 0 - no): ";
        cin >> playChoice;

        if (playChoice == 1)
        {
            playMorse(morse);
        }
    }
    else
    {
        char result[5000];

        morseToText(text, result);

        cout << endl << "Morse: " << text << endl;
        cout << "Decoded: " << result << endl;

        ofstream outFile("decoded_output.txt");

        outFile << result << endl;

        outFile.close();

        cout << "Saved to decoded_output.txt" << endl;
    }

    return 0;
}