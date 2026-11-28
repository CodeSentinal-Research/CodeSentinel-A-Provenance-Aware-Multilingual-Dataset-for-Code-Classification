#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    int n;
    if (std::cin >> n) {
        std::unordered_map<std::string, std::string> records;
        for (int i = 0; i < n; i++) {
            std::string isbn, title;
            std::cin >> isbn >> title;
            records[isbn] = title;
        }
        std::string target;
        std::cin >> target;
        if (records.count(target)) {
            std::cout << target << " " << records[target] << std::endl;
        } else {
            std::cout << "Book Not Found" << std::endl;
        }
    }
    return 0;
}