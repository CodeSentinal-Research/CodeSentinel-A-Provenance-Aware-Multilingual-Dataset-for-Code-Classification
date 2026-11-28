#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

int main() {
    std::unordered_set<char> r1 = {'q','w','e','r','t','y','u','i','o','p'};
    std::unordered_set<char> r2 = {'a','s','d','f','g','h','j','k','l'};
    std::unordered_set<char> r3 = {'z','x','c','v','b','n','m'};
    std::string word;
    while (std::cin >> word) {
        int mask = 0;
        for (char c : word) {
            char lower_c = tolower(c);
            if (r1.count(lower_c)) mask |= 1;
            else if (r2.count(lower_c)) mask |= 2;
            else if (r3.count(lower_c)) mask |= 4;
        }
        if (mask == 1 || mask == 2 || mask == 4) {
            std::cout << word << "\n";
        }
    }
    return 0;
}