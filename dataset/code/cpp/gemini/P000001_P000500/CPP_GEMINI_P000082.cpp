#include <iostream>
#include <cctype>

int main() {
    // Optimize input/output operations for competitive programming
    std::ios_base::sync_with_stdio(false);
    // Optimize standard I/O operations for performance
    std::cin.tie(NULL);

    char ch;
    if (std::cin >> ch) {
        // A character is a special symbol if it is neither an alphabet nor a digit.
        if (std::isalnum(static_cast<unsigned char>(ch))) {
            std::cout << "Not a Special Symbol\n";
        } else {
            std::cout << "Special Symbol\n";
        }
    }
    return 0;
}