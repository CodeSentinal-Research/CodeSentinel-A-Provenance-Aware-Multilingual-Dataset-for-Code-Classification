#include <iostream>
#include <string>
#include <sstream>
int main() {
    std::string s;
    if (std::cin >> s) {
        std::stringstream ss(s);
        std::string node;
        int slots = 1;
        bool valid = true;
        while (std::getline(ss, node, ',')) {
            slots--;
            if (slots < 0) { valid = false; break; }
            if (node != "#") slots += 2;
        }
        if (slots != 0) valid = false;
        std::cout << (valid ? "true" : "false") << std::endl;
    }
    return 0;
}