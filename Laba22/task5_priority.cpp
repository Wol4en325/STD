#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Ticket
{
    int priority;
    string category;
    string text;

    bool operator<(const Ticket &other) const
    {
        return priority < other.priority;
    }
};

int main()
{
    priority_queue<Ticket> pq;

    int n;
    cout << "Enter number of tickets: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        Ticket t;
        cout << endl << "Ticket " << i + 1 << ":" << endl;
        cout << "Enter priority (1 = low, 2 = medium, 3 = high): ";
        cin >> t.priority;
        cin.ignore();

        if (t.priority == 3) t.category = "high";
        else if (t.priority == 2) t.category = "medium";
        else t.category = "low";

        cout << "Enter ticket text: ";
        getline(cin, t.text);

        pq.push(t);
    }

    cout << endl << "=== Processing tickets by priority ===" << endl;
    while (!pq.empty())
    {
        Ticket t = pq.top();
        pq.pop();
        cout << "Category: " << t.category;
        cout << " | Text: " << t.text << endl;
    }

    return 0;
}
