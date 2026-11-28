#include <iostream>
#include <stack>
#include <unordered_map>

bool isValid(std::string s) {
    std::unordered_map<char, char> mapping = {{')', '('}, {'}', '{'}, {']', '['}};
    std::stack<char> stack;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
        } else if (stack.empty() || mapping[c] != stack.top()) {
            return false;
        } else {
            stack.pop();
        }
    }

    return stack.empty();
}

int main() {
    std::string s;
    std::cin >> s;
    if (isValid(s)) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }
    return 0;
}