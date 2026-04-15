#include <iostream>
#include <cstring>

using namespace std;

enum MediaType
{
    VINYL = 1,
    CASSETTE,
    CD
};

struct MusicRecord
{
    MediaType media;
    char title[50];
    char artist[50];
    double duration;
    int trackCount;
    double price;
};

struct Node
{
    MusicRecord data;
    Node* next;
};

void push(Node* &top, MusicRecord record)
{
    Node* newNode = new Node;
    newNode->data = record;
    newNode->next = top;
    top = newNode;
}

MusicRecord pop(Node* &top)
{
    MusicRecord value = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return value;
}

bool isEmpty(Node* top)
{
    return top == NULL;
}

void printRecord(MusicRecord r)
{
    cout << "Title: " << r.title << endl;
    cout << "Artist: " << r.artist << endl;
    cout << "Duration: " << r.duration << " min" << endl;
    cout << "Tracks: " << r.trackCount << endl;
    cout << "Price: $" << r.price << endl;

    if (r.media == VINYL)
        cout << "Media: Vinyl" << endl;
    else if (r.media == CASSETTE)
        cout << "Media: Cassette" << endl;
    else if (r.media == CD)
        cout << "Media: CD" << endl;

    cout << "----------------------------" << endl;
}

void freeStack(Node* &top)
{
    while (!isEmpty(top))
        pop(top);
}

int main()
{
    Node* stack = NULL;
    int n;

    cout << "Enter number of records: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        MusicRecord r;
        cout << endl << "Record " << i + 1 << ":" << endl;

        cout << "Title: ";
        cin.getline(r.title, 50);

        cout << "Artist: ";
        cin.getline(r.artist, 50);

        cout << "Duration (min): ";
        cin >> r.duration;

        cout << "Track count: ";
        cin >> r.trackCount;

        cout << "Price ($): ";
        cin >> r.price;

        cout << "Media (1 - Vinyl, 2 - Cassette, 3 - CD): ";
        int m;
        cin >> m;
        cin.ignore();
        r.media = (MediaType)m;

        push(stack, r);
    }

    char searchArtist[50];
    cout << endl << "Enter artist name to search: ";
    cin.getline(searchArtist, 50);

    Node* tempStack = NULL;
    double totalDuration = 0;

    while (!isEmpty(stack))
    {
        MusicRecord r = pop(stack);
        if (strcmp(r.artist, searchArtist) == 0)
            totalDuration += r.duration;
        push(tempStack, r);
    }

    while (!isEmpty(tempStack))
    {
        MusicRecord r = pop(tempStack);
        push(stack, r);
    }

    cout << "Total duration for artist \"" << searchArtist << "\": " << totalDuration << " min" << endl;

    Node* cassetteStack = NULL;

    while (!isEmpty(stack))
    {
        MusicRecord r = pop(stack);
        if (r.media == CASSETTE)
            push(cassetteStack, r);
        push(tempStack, r);
    }

    while (!isEmpty(tempStack))
    {
        MusicRecord r = pop(tempStack);
        push(stack, r);
    }

    cout << endl << "Cassette records:" << endl;
    double priceSum = 0;
    int count = 0;
    Node* current = cassetteStack;
    while (current != NULL)
    {
        printRecord(current->data);
        priceSum += current->data.price;
        count++;
        current = current->next;
    }

    if (count > 0)
        cout << "Average price of cassette records: $" << priceSum / count << endl;
    else
        cout << "No cassette records found." << endl;

    freeStack(stack);
    freeStack(cassetteStack);
    cout << "Memory freed." << endl;

    return 0;
}
