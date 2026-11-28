#include <iostream>
#include <vector>
#include <string>

struct Record {
    std::string description;
};

int main() {
    int numRecords;
    std::string keyword;

    std::cin >> numRecords;
    std::cin.ignore();

    std::vector<Record> records(numRecords);
    for (int i = 0; i < numRecords; ++i) {
        std::getline(std::cin, records[i].description);
    }

    std::cin >> keyword;

    for (const auto& record : records) {
        if (record.description.find(keyword) != std::string::npos) {
            std::cout << record.description << '\n';
        }
    }

    return 0;
}