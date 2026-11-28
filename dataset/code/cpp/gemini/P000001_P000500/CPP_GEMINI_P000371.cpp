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
        std::string target_id;
        std::cin >> target_id;
        if (records.count(target_id)) {
            std::cout << target_id << " " << records[target_id] << std::endl;
        } else {
            std::cout << "Record Not Found" << std::endl;
        }
    }
    return 0;
}