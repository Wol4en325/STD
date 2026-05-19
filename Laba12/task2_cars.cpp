#include <iostream>
#include <list>
#include <string>

using namespace std;

struct Car
{
    string name;
    int year;
    int mileage;
};

void printCar(Car &c)
{
    cout << "Name: " << c.name;
    cout << " | Year: " << c.year;
    cout << " | Mileage: " << c.mileage << " km" << endl;
}

void addFirst(list<Car> &cars)
{
    Car c;
    cout << "Enter car name: ";
    cin.ignore();
    getline(cin, c.name);
    cout << "Enter year: ";
    cin >> c.year;
    cout << "Enter mileage: ";
    cin >> c.mileage;
    cars.push_front(c);
    cout << "Car added to the beginning." << endl;
}

void addToBeginning(list<Car> &cars)
{
    Car c;
    cout << "Enter car name: ";
    cin.ignore();
    getline(cin, c.name);
    cout << "Enter year: ";
    cin >> c.year;
    cout << "Enter mileage: ";
    cin >> c.mileage;
    cars.push_front(c);
    cout << "Car added to the beginning." << endl;
}

void addToEnd(list<Car> &cars)
{
    Car c;
    cout << "Enter car name: ";
    cin.ignore();
    getline(cin, c.name);
    cout << "Enter year: ";
    cin >> c.year;
    cout << "Enter mileage: ";
    cin >> c.mileage;
    cars.push_back(c);
    cout << "Car added to the end." << endl;
}

void addAfter(list<Car> &cars)
{
    string targetName;
    cout << "Enter name of car to insert after: ";
    cin.ignore();
    getline(cin, targetName);

    list<Car>::iterator it;
    bool found = false;
    for (it = cars.begin(); it != cars.end(); it++)
    {
        if (it->name == targetName)
        {
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Car not found." << endl;
        return;
    }

    Car c;
    cout << "Enter new car name: ";
    getline(cin, c.name);
    cout << "Enter year: ";
    cin >> c.year;
    cout << "Enter mileage: ";
    cin >> c.mileage;

    it++;
    cars.insert(it, c);
    cout << "Car inserted." << endl;
}

void addBefore(list<Car> &cars)
{
    string targetName;
    cout << "Enter name of car to insert before: ";
    cin.ignore();
    getline(cin, targetName);

    list<Car>::iterator it;
    bool found = false;
    for (it = cars.begin(); it != cars.end(); it++)
    {
        if (it->name == targetName)
        {
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Car not found." << endl;
        return;
    }

    Car c;
    cout << "Enter new car name: ";
    getline(cin, c.name);
    cout << "Enter year: ";
    cin >> c.year;
    cout << "Enter mileage: ";
    cin >> c.mileage;

    cars.insert(it, c);
    cout << "Car inserted." << endl;
}

void searchCar(list<Car> &cars)
{
    string name;
    cout << "Enter car name to search: ";
    cin.ignore();
    getline(cin, name);

    for (list<Car>::iterator it = cars.begin(); it != cars.end(); it++)
    {
        if (it->name == name)
        {
            cout << "Car with name " << name << " is in the list." << endl;
            return;
        }
    }
    cout << "Car with name " << name << " is NOT in the list." << endl;
}

void deleteByYear(list<Car> &cars)
{
    int year;
    cout << "Delete cars with year less than: ";
    cin >> year;

    list<Car>::iterator it = cars.begin();
    int count = 0;
    while (it != cars.end())
    {
        if (it->year < year)
        {
            it = cars.erase(it);
            count++;
        }
        else
        {
            it++;
        }
    }
    cout << "Deleted " << count << " car(s)." << endl;
}

void printAll(list<Car> &cars)
{
    if (cars.empty())
    {
        cout << "List is empty." << endl;
        return;
    }
    int i = 1;
    for (list<Car>::iterator it = cars.begin(); it != cars.end(); it++)
    {
        cout << i << ". ";
        printCar(*it);
        i++;
    }
}

int main()
{
    list<Car> cars;
    int choice = 0;

    while (choice != 9)
    {
        cout << endl;
        cout << "-------- MENU FOR WORKING WITH LIST --------" << endl;
        cout << "1. Add first element to the list" << endl;
        cout << "2. Insert element at the beginning" << endl;
        cout << "3. Insert element at the end" << endl;
        cout << "4. Insert element after a given element" << endl;
        cout << "5. Insert element before a given element" << endl;
        cout << "6. Search for a node" << endl;
        cout << "7. Delete node by year (less than given)" << endl;
        cout << "8. View list" << endl;
        cout << "9. Exit" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "Enter operation number: ";
        cin >> choice;

        if (choice == 1) addFirst(cars);
        else if (choice == 2) addToBeginning(cars);
        else if (choice == 3) addToEnd(cars);
        else if (choice == 4) addAfter(cars);
        else if (choice == 5) addBefore(cars);
        else if (choice == 6) searchCar(cars);
        else if (choice == 7) deleteByYear(cars);
        else if (choice == 8) printAll(cars);
        else if (choice == 9) cout << "Exiting." << endl;
        else cout << "Invalid choice." << endl;
    }

    return 0;
}
