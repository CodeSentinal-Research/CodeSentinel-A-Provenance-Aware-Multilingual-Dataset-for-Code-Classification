#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int n;
    if (std::cin >> n) {
        for (int i = 0; i < n; i++) {
            std::string room, status;
            std::cin >> room >> status;
            std::string lower_status = status;
            std::transform(lower_status.begin(), lower_status.end(), lower_status.begin(), ::tolower);
            if (lower_status == "available" || lower_status == "true" || lower_status == "1" || lower_status == "yes" || lower_status == "free") {
                std::cout << room << "\n";
            }
        }
    }
    return 0;
}