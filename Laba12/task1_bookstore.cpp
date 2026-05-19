#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Book
{
    string title;
    string genre;
    double price;
    int popularity;
    int arrivalDate;
    bool sold;
};

void addBook(vector<Book> &books)
{
    Book b;
    cout << "Enter title: ";
    cin.ignore();
    getline(cin, b.title);
    cout << "Enter genre: ";
    getline(cin, b.genre);
    cout << "Enter price: ";
    cin >> b.price;
    cout << "Enter popularity (1-100): ";
    cin >> b.popularity;
    cout << "Enter arrival date (e.g. 20240101): ";
    cin >> b.arrivalDate;
    b.sold = false;
    books.push_back(b);
    cout << "Book added." << endl;
}

void removeSold(vector<Book> &books)
{
    int before = books.size();
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].sold)
        {
            books.erase(books.begin() + i);
            i--;
        }
    }
    cout << "Removed " << before - books.size() << " sold book(s)." << endl;
}

void markAsSold(vector<Book> &books)
{
    string title;
    cout << "Enter title to mark as sold: ";
    cin.ignore();
    getline(cin, title);
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].title == title)
        {
            books[i].sold = true;
            cout << "Marked as sold." << endl;
            return;
        }
    }
    cout << "Book not found." << endl;
}

void sortByPrice(vector<Book> &books)
{
    for (int i = 0; i < books.size(); i++)
    {
        for (int j = i + 1; j < books.size(); j++)
        {
            if (books[i].price > books[j].price)
            {
                Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
    cout << "Sorted by price." << endl;
}

void sortByPopularity(vector<Book> &books)
{
    for (int i = 0; i < books.size(); i++)
    {
        for (int j = i + 1; j < books.size(); j++)
        {
            if (books[i].popularity < books[j].popularity)
            {
                Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
    cout << "Sorted by popularity." << endl;
}

void sortByDate(vector<Book> &books)
{
    for (int i = 0; i < books.size(); i++)
    {
        for (int j = i + 1; j < books.size(); j++)
        {
            if (books[i].arrivalDate > books[j].arrivalDate)
            {
                Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
    cout << "Sorted by arrival date." << endl;
}

void filterByGenre(vector<Book> &books)
{
    string genre;
    cout << "Enter genre: ";
    cin.ignore();
    getline(cin, genre);
    bool found = false;
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].genre == genre)
        {
            cout << "Title: " << books[i].title;
            cout << ", Price: " << books[i].price;
            cout << ", Popularity: " << books[i].popularity << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << "No books found in this genre." << endl;
    }
}

void filterByPrice(vector<Book> &books)
{
    double minPrice, maxPrice;
    cout << "Enter min price: ";
    cin >> minPrice;
    cout << "Enter max price: ";
    cin >> maxPrice;
    bool found = false;
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].price >= minPrice && books[i].price <= maxPrice)
        {
            cout << "Title: " << books[i].title;
            cout << ", Genre: " << books[i].genre;
            cout << ", Price: " << books[i].price << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << "No books found in this price range." << endl;
    }
}

void searchBook(vector<Book> &books)
{
    string title;
    cout << "Enter title to search: ";
    cin.ignore();
    getline(cin, title);
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].title == title)
        {
            cout << "Found: " << books[i].title;
            cout << ", Genre: " << books[i].genre;
            cout << ", Price: " << books[i].price;
            cout << ", Popularity: " << books[i].popularity;
            cout << ", Sold: " << (books[i].sold ? "yes" : "no") << endl;
            return;
        }
    }
    cout << "Book not found." << endl;
}

void printAll(vector<Book> &books)
{
    if (books.size() == 0)
    {
        cout << "List is empty." << endl;
        return;
    }
    for (int i = 0; i < books.size(); i++)
    {
        cout << i + 1 << ". " << books[i].title;
        cout << " | Genre: " << books[i].genre;
        cout << " | Price: " << books[i].price;
        cout << " | Popularity: " << books[i].popularity;
        cout << " | Date: " << books[i].arrivalDate;
        cout << " | Sold: " << (books[i].sold ? "yes" : "no") << endl;
    }
}

int main()
{
    vector<Book> books;
    int choice = 0;

    while (choice != 9)
    {
        cout << endl;
        cout << "=== Bookstore Menu ===" << endl;
        cout << "1. Add book" << endl;
        cout << "2. Mark book as sold" << endl;
        cout << "3. Remove sold books" << endl;
        cout << "4. Sort by price" << endl;
        cout << "5. Sort by popularity" << endl;
        cout << "6. Sort by arrival date" << endl;
        cout << "7. Filter by genre" << endl;
        cout << "8. Filter by price range" << endl;
        cout << "9. Search book" << endl;
        cout << "10. Print all books" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) addBook(books);
        else if (choice == 2) markAsSold(books);
        else if (choice == 3) removeSold(books);
        else if (choice == 4) sortByPrice(books);
        else if (choice == 5) sortByPopularity(books);
        else if (choice == 6) sortByDate(books);
        else if (choice == 7) filterByGenre(books);
        else if (choice == 8) filterByPrice(books);
        else if (choice == 9) searchBook(books);
        else if (choice == 10) printAll(books);
        else if (choice == 0) break;
        else cout << "Invalid choice." << endl;
    }

    return 0;
}
