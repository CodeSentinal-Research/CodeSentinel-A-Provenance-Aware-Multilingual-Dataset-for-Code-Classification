#include <iostream>
#include <string>

int main() {
    std::string s;
    if (std::cin >> s) {
        int unbalanced = 0;
        for (char c : s) {
            if (c == '[') {
                if (unbalanced > 0) unbalanced--;
            } else {
                unbalanced++;
            }
        }
        std::cout << (unbalanced + 1) / 2 << "\n";
    }
    return 0;
}