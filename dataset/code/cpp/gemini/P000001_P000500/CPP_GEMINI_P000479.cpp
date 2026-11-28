#include <iostream>
#include <string>
#include <stack>
bool isValid(const std::string& s) {
    std::stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') st.push(c);
        else {
            if (st.empty()) return false;
            if (c == ')' && st.top() != '(') return false;
            if (c == '}' && st.top() != '{') return false;
            if (c == ']' && st.top() != '[') return false;
            st.pop();
        }
    }
    return st.empty();
}
int main() {
    std::string s;
    if (std::cin >> s) {
        std::cout << (isValid(s) ? "true" : "false") << std::endl;
    }
    return 0;
}