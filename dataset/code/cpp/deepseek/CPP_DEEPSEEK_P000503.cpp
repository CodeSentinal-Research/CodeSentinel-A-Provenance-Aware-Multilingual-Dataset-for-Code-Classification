#include <iostream>
#include <stack>
#include <string>

int scoreOfParentheses(std::string s) {
    std::stack<char> stk;
    int result = 0, temp = 0;

    for(char c : s) {
        if (c == '(') {
            stk.push(c);
        } else {
            if(stk.top() == '(') {
                stk.pop();
                if (stk.empty()) {
                    result += temp;
                } else {
                    temp += temp;
                }
            } else {
                temp += temp;
            }
        }
    }

    return result;
}

int main() {
    std::string s;
    std::cin >> s;
    std::cout << scoreOfParentheses(s);
    return 0;
}