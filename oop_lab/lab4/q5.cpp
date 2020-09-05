#include <iostream>
#include <string>

using namespace std;

class Book
{
private:
    string name;
    string author;
    int price;

public:
    void set(string &name, string &author, int &price)
    {
        Book::name = name;
        Book::author = author;
        Book::price = price;
    };
    int get()
    {
        return price;
    };
    friend void print_book(Book &b);
};

void print_book(Book &b)
{
    cout << "Book Name: " << b.name << endl;
    cout << "Book Author: " << b.author << endl;
    cout << "Book Name: " << b.price << endl
         << endl;
}

int main()
{
    int n;
    cout << "Enter Number of Books: ";
    cin >> n;

    Book books[10];

    for (int i = 0; i < n; i++)
    {
        string name, author;
        int price;

        cout << "Enter Book's Name: ";
        cin >> name;

        cout << "Enter Authors Name: ";
        cin >> author;

        cout << "Enter Book's Price: ";
        cin >> price;

        books[i].set(name, author, price);
    }
    int min, max;
    cout << "enter the price range,first min then max" << endl;
    cin >> min >> max;

    for (int i = 0; i < n; i++)
    {
        if (books[i].get() >= min && books[i].get() <= max)
            print_book(books[i]);
    }

    return 0;
}