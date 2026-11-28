#include <iostream>
#include <string>
#include <vector>

int shortestWay(std::string source, std::string target) {
    int i = 0, count = 0;
    while (i < (int)target.length()) {
        int initial_i = i;
        for (char c : source) {
            if (i < (int)target.length() && c == target[i]) {
                i++;
            }
        }
        if (i == initial_i) return -1;
        count++;
    }
    return count;
}

int main() {
    std::string s, t;
    if (std::cin >> s >> t) {
        std::cout << shortestWay(s, t) << std::endl;
    }
    return 0;
}