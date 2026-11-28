#include <iostream>
#include <string>
#include <stack>
int main() {
    std::string s;
    if (std::cin >> s) {
        std::stack<char> st;
        bool valid = true;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') st.push(c);
            else {
                if (st.empty()) { valid = false; break; }
                char t = st.top(); st.pop();
                if ((c == ')' && t != '(') || (c == '}' && t != '{') || (c == ']' && t != '[')) {
                    valid = false; break;
                }
            }
        }
        std::cout << (valid && st.empty() ? "Valid" : "Invalid") << std::endl;
    }
    return 0;
}