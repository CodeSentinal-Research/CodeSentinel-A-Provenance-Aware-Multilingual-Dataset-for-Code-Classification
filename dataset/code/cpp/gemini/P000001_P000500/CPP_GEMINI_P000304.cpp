#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main() {
    std::string path;
    if (std::cin >> path) {
        std::stringstream ss(path);
        std::string part;
        std::vector<std::string> stack;
        while (std::getline(ss, part, '/')) {
            if (part.empty() || part == ".") continue;
            if (part == "..") {
                if (!stack.empty()) stack.pop_back();
            } else {
                stack.push_back(part);
            }
        }
        std::string res = "";
        for (const auto& s : stack) {
            res += "/" + s;
        }
        std::cout << (res.empty() ? "/" : res) << std::endl;
    }
    return 0;
}