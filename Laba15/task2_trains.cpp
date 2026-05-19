#include <iostream>
#include <string>

using namespace std;

struct Time
{
    int hours;
    int minutes;
};

struct Train
{
    int number;
    string destination;
    int distance;
    Time departure;
    Time arrival;
    int travelTime;
};

void printTrain(Train &t)
{
    cout << "Train #" << t.number;
    cout << " | Destination: " << t.destination;
    cout << " | Distance: " << t.distance << " km";
    cout << " | Departure: " << t.departure.hours << ":" ;
    if (t.departure.minutes < 10) cout << "0";
    cout << t.departure.minutes;
    cout << " | Arrival: " << t.arrival.hours << ":";
    if (t.arrival.minutes < 10) cout << "0";
    cout << t.arrival.minutes;
    cout << " | Travel time: " << t.travelTime << " min" << endl;
}

void selectionSort(Train trains[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (trains[j].travelTime > trains[maxIndex].travelTime)
            {
                maxIndex = j;
            }
        }
        Train temp = trains[i];
        trains[i] = trains[maxIndex];
        trains[maxIndex] = temp;
    }
}

int main()
{
    int n;
    cout << "Enter number of trains: ";
    cin >> n;

    Train trains[100];

    for (int i = 0; i < n; i++)
    {
        cout << endl << "Train " << i + 1 << ":" << endl;
        cout << "Enter train number: ";
        cin >> trains[i].number;
        cout << "Enter destination: ";
        cin >> trains[i].destination;
        cout << "Enter distance (km): ";
        cin >> trains[i].distance;
        cout << "Enter departure time (hours minutes): ";
        cin >> trains[i].departure.hours >> trains[i].departure.minutes;
        cout << "Enter arrival time (hours minutes): ";
        cin >> trains[i].arrival.hours >> trains[i].arrival.minutes;
        cout << "Enter travel time (minutes): ";
        cin >> trains[i].travelTime;
    }

    cout << endl << "=== All trains ===" << endl;
    for (int i = 0; i < n; i++)
    {
        printTrain(trains[i]);
    }

    int maxTime = trains[0].travelTime;
    int maxIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (trains[i].travelTime > maxTime)
        {
            maxTime = trains[i].travelTime;
            maxIndex = i;
        }
    }

    cout << endl << "=== Train with longest travel time (linear search) ===" << endl;
    printTrain(trains[maxIndex]);

    selectionSort(trains, n);

    cout << endl << "=== Sorted by travel time (descending) ===" << endl;
    for (int i = 0; i < n; i++)
    {
        printTrain(trains[i]);
    }

    cout << endl << "=== Train with max travel time (after selection sort) ===" << endl;
    cout << "Train #" << trains[0].number;
    cout << " | Destination: " << trains[0].destination;
    cout << " | Travel time: " << trains[0].travelTime << " min" << endl;

    return 0;
}
