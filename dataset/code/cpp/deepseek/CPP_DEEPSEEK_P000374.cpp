#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Book {
    string title;
    string author;
    string isbn;
};

int main() {
    int n;
    cin >> n;

    vector<Book> books(n);

    for (int i = 0; i < n; i++) {
        cin >> books[i].title >> books[i].author >> books[i].isbn;
    }

    string isbn;
    cin >> isbn;

    bool found = false;

    for (int i = 0; i < n; i++) {
        if (books[i].isbn == isbn) {
            cout << books[i].title << " " << books[i].author << " " << books[i].isbn << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Book Not Found" << endl;
    }

    return 0;
}
This C++ code defines a struct Book to store book details and a main function to input a collection of books and an ISBN, then search the collection for the book with the given ISBN. If the book is found, it prints the book's details. If not, it outputs "Book Not Found".