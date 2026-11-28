#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main() {
    std::string s;
    if (std::cin >> s) {
        std::sort(s.begin(), s.end());
        do {
            std::cout << s << std::endl;
        } while (std::next_permutation(s.begin(), s.end()));
    }
    return 0;
}