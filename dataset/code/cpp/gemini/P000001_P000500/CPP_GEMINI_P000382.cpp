#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    int n;
    if (std::cin >> n) {
        std::unordered_map<std::string, std::string> records;
        for (int i = 0; i < n; i++) {
            std::string uname, email;
            std::cin >> uname >> email;
            records[uname] = email;
        }
        std::string target;
        std::cin >> target;
        if (records.count(target)) {
            std::cout << records[target] << std::endl;
        } else {
            std::cout << "User Not Found" << std::endl;
        }
    }
    return 0;
}