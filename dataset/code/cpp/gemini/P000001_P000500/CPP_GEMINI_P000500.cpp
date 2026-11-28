#include <iostream>
#include <string>
int main() {
    int n;
    if (std::cin >> n) {
        int depth = 0;
        for (int i = 0; i < n; i++) {
            std::string op;
            std::cin >> op;
            if (op == "../") {
                if (depth > 0) depth--;
            } else if (op == "./") {
            } else {
                depth++;
            }
        }
        std::cout << depth << std::endl;
    }
    return 0;
}