#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    int n;
    if (std::cin >> n) {
        std::unordered_map<std::string, std::string> records;
        for (int i = 0; i < n; i++) {
            std::string id, name;
            std::cin >> id >> name;
            records[id] = name;
        }
        std::string target;
        std::cin >> target;
        if (records.count(target)) {
            std::cout << target << " " << records[target] << std::endl;
        } else {
            std::cout << "Member Not Found" << std::endl;
        }
    }
    return 0;
}