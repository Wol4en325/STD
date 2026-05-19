#include <iostream>

using namespace std;

struct Activity
{
    int start;
    int end;
    int index;
};

void sortByEnd(Activity arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].end > arr[j + 1].end)
            {
                Activity temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    Activity activities[100];

    for (int i = 0; i < n; i++)
    {
        activities[i].index = i + 1;
        cout << "Activity " << i + 1 << " - start time: ";
        cin >> activities[i].start;
        cout << "Activity " << i + 1 << " - end time: ";
        cin >> activities[i].end;
    }

    sortByEnd(activities, n);

    cout << endl << "Activities sorted by end time:" << endl;
    for (int i = 0; i < n; i++)
        cout << "Activity " << activities[i].index
             << ": [" << activities[i].start << " - " << activities[i].end << "]" << endl;

    Activity selected[100];
    int selectedCount = 0;

    selected[0] = activities[0];
    selectedCount = 1;
    int lastEnd = activities[0].end;

    for (int i = 1; i < n; i++)
    {
        if (activities[i].start >= lastEnd)
        {
            selected[selectedCount] = activities[i];
            selectedCount++;
            lastEnd = activities[i].end;
        }
    }

    cout << endl << "Selected activities (" << selectedCount << " total):" << endl;
    for (int i = 0; i < selectedCount; i++)
    {
        cout << "Activity " << selected[i].index
             << ": start = " << selected[i].start
             << ", end = " << selected[i].end << endl;
    }

    return 0;
}
