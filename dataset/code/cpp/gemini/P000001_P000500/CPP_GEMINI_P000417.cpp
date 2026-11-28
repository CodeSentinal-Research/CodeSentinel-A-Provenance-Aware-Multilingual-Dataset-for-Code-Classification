#include <iostream>
#include <string>
#include <vector>
struct Book { std::string title, author, genre; };
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<Book> books(n);
        for (int i = 0; i < n; i++) std::cin >> books[i].title >> books[i].author >> books[i].genre;
        std::string a, g;
        std::cin >> a >> g;
        for (const auto& b : books) {
            if (b.author == a && b.genre == g) std::cout << b.title << "\n";
        }
    }
    return 0;
}