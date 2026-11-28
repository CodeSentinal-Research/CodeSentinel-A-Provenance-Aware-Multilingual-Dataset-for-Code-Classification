#include <iostream>
#include <vector>
#include <algorithm>

struct Book {
    int year;
    std::string title;
};

bool compare(const Book& a, const Book& b) {
    return a.year < b.year;
}

int main() {
    int n, year;
    std::cin >> n;
    std::vector<Book> books(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> books[i].year >> books[i].title;
    }
    std::cin >> year;
    std::vector<Book> result;
    for (const Book& book : books) {
        if (book.year > year) {
            result.push_back(book);
        }
    }
    std::sort(result.begin(), result.end(), compare);
    for (const Book& book : result) {
        std::cout << book.year << " " << book.title << "\n";
    }
    return 0;
}