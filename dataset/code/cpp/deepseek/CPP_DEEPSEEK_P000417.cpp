Here is the C++ code snippet for the problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Book {
    string title;
    string author;
    string genre;
};

vector<Book> books;

vector<Book> SearchBooksByAuthorAndGenre(string author, string genre) {
    vector<Book> matchingBooks;
    for (Book book : books) {
        if (book.author == author && book.genre == genre) {
            matchingBooks.push_back(book);
        }
    }
    return matchingBooks;
}

int main() {
    int n;
    cin >> n;
    books.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> books[i].title >> books[i].author >> books[i].genre;
    }

    string author;
    cin >> author;
    string genre;
    cin >> genre;

    vector<Book> matchingBooks = SearchBooksByAuthorAndGenre(author, genre);
    for (Book book : matchingBooks) {
        cout << book.title << " " << book.author << " " << book.genre << endl;
    }

    return 0;
}

In this code, we first define a struct `Book` to represent a book with its title, author, and genre. We then declare a vector `books` of `Book` objects. 

The `SearchBooksByAuthorAndGenre` function takes an author name and a genre, and returns all books written by the given author that belong to the given genre. 

In the main function, we first read the number of books, then we read each book. We then read the author and genre, and call `SearchBooksByAuthorAndGenre` to get all matching books. Finally, we print out the titles, authors, and genres of the matching books.