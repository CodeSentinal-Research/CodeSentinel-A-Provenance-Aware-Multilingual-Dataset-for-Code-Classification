#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    int n;
    if (std::cin >> n) {
        std::unordered_map<std::string, std::string> records;
        for (int i = 0; i < n; i++) {
            std::string roll, name;
            std::cin >> roll >> name;
            records[roll] = name;
        }
        std::string target_roll;
        std::cin >> target_roll;
        if (records.count(target_roll)) {
            std::cout << target_roll << " " << records[target_roll] << std::endl;
        } else {
            std::cout << "Record Not Found" << std::endl;
        }
    }
    return 0;
}