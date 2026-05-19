#include <iostream>
#include <deque>
#include <string>

using namespace std;

struct Order
{
    int number;
    string clientName;
    string address;
    double price;
    bool urgent;
    string time;
    string status;
};

void printOrder(Order &o)
{
    cout << "Order #" << o.number;
    cout << " | Client: " << o.clientName;
    cout << " | Address: " << o.address;
    cout << " | Price: " << o.price;
    cout << " | Urgent: " << (o.urgent ? "yes" : "no");
    cout << " | Time: " << o.time;
    cout << " | Status: " << o.status << endl;
}

void addOrder(deque<Order> &orders)
{
    Order o;
    cout << "Enter order number: ";
    cin >> o.number;
    cout << "Enter client name: ";
    cin.ignore();
    getline(cin, o.clientName);
    cout << "Enter address: ";
    getline(cin, o.address);
    cout << "Enter price: ";
    cin >> o.price;
    cout << "Is urgent? (1 = yes, 0 = no): ";
    cin >> o.urgent;
    cout << "Enter time (e.g. 10:30): ";
    cin.ignore();
    getline(cin, o.time);
    o.status = "pending";

    if (o.urgent)
    {
        orders.push_front(o);
        cout << "Urgent order added to the front." << endl;
    }
    else
    {
        orders.push_back(o);
        cout << "Order added to the end." << endl;
    }
}

void removeCompleted(deque<Order> &orders)
{
    int count = 0;
    for (int i = 0; i < orders.size(); i++)
    {
        if (orders[i].status == "done" || orders[i].status == "cancelled")
        {
            orders.erase(orders.begin() + i);
            i--;
            count++;
        }
    }
    cout << "Removed " << count << " order(s)." << endl;
}

void searchByNumber(deque<Order> &orders)
{
    int num;
    cout << "Enter order number: ";
    cin >> num;
    for (int i = 0; i < orders.size(); i++)
    {
        if (orders[i].number == num)
        {
            printOrder(orders[i]);
            return;
        }
    }
    cout << "Order not found." << endl;
}

void searchByClient(deque<Order> &orders)
{
    string name;
    cout << "Enter client name: ";
    cin.ignore();
    getline(cin, name);
    bool found = false;
    for (int i = 0; i < orders.size(); i++)
    {
        if (orders[i].clientName == name)
        {
            printOrder(orders[i]);
            found = true;
        }
    }
    if (!found)
    {
        cout << "No orders found for this client." << endl;
    }
}

void searchByStatus(deque<Order> &orders)
{
    string status;
    cout << "Enter status (pending/done/cancelled): ";
    cin.ignore();
    getline(cin, status);
    bool found = false;
    for (int i = 0; i < orders.size(); i++)
    {
        if (orders[i].status == status)
        {
            printOrder(orders[i]);
            found = true;
        }
    }
    if (!found)
    {
        cout << "No orders with this status." << endl;
    }
}

void editOrder(deque<Order> &orders)
{
    int num;
    cout << "Enter order number to edit: ";
    cin >> num;
    for (int i = 0; i < orders.size(); i++)
    {
        if (orders[i].number == num)
        {
            cout << "Enter new status (pending/done/cancelled): ";
            cin.ignore();
            getline(cin, orders[i].status);
            cout << "Enter new price: ";
            cin >> orders[i].price;
            cout << "Order updated." << endl;
            return;
        }
    }
    cout << "Order not found." << endl;
}

void sortByPrice(deque<Order> &orders)
{
    for (int i = 0; i < orders.size(); i++)
    {
        for (int j = i + 1; j < orders.size(); j++)
        {
            if (orders[i].price > orders[j].price)
            {
                Order temp = orders[i];
                orders[i] = orders[j];
                orders[j] = temp;
            }
        }
    }
    cout << "Sorted by price." << endl;
}

void filterByPriceRange(deque<Order> &orders)
{
    double minP, maxP;
    cout << "Enter min price: ";
    cin >> minP;
    cout << "Enter max price: ";
    cin >> maxP;
    bool found = false;
    for (int i = 0; i < orders.size(); i++)
    {
        if (orders[i].price >= minP && orders[i].price <= maxP)
        {
            printOrder(orders[i]);
            found = true;
        }
    }
    if (!found)
    {
        cout << "No orders in this price range." << endl;
    }
}

void filterByUrgent(deque<Order> &orders)
{
    bool urgent;
    cout << "Show urgent only? (1 = yes, 0 = no): ";
    cin >> urgent;
    bool found = false;
    for (int i = 0; i < orders.size(); i++)
    {
        if (orders[i].urgent == urgent)
        {
            printOrder(orders[i]);
            found = true;
        }
    }
    if (!found)
    {
        cout << "No orders found." << endl;
    }
}

void printAll(deque<Order> &orders)
{
    if (orders.empty())
    {
        cout << "Queue is empty." << endl;
        return;
    }
    for (int i = 0; i < orders.size(); i++)
    {
        printOrder(orders[i]);
    }
}

int main()
{
    deque<Order> orders;
    int choice = 0;

    while (choice != 0)
    {
        cout << endl;
        cout << "=== Delivery Service Menu ===" << endl;
        cout << "1. Add order" << endl;
        cout << "2. Remove completed/cancelled orders" << endl;
        cout << "3. Search by order number" << endl;
        cout << "4. Search by client name" << endl;
        cout << "5. Search by status" << endl;
        cout << "6. Edit order" << endl;
        cout << "7. Sort by price" << endl;
        cout << "8. Filter by price range" << endl;
        cout << "9. Filter by priority (urgent/normal)" << endl;
        cout << "10. Print all orders" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) addOrder(orders);
        else if (choice == 2) removeCompleted(orders);
        else if (choice == 3) searchByNumber(orders);
        else if (choice == 4) searchByClient(orders);
        else if (choice == 5) searchByStatus(orders);
        else if (choice == 6) editOrder(orders);
        else if (choice == 7) sortByPrice(orders);
        else if (choice == 8) filterByPriceRange(orders);
        else if (choice == 9) filterByUrgent(orders);
        else if (choice == 10) printAll(orders);
        else if (choice == 0) cout << "Exiting." << endl;
        else cout << "Invalid choice." << endl;
    }

    return 0;
}
