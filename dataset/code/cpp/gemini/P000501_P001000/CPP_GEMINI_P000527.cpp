#include <iostream>
#include <string>
#include <vector>
#include <stack>
int main() {
    std::string s;
    if (std::cin >> s) {
        std::stack<char> st;
        for (char c : s) {
            if (c == ',' || c == '(') continue;
            if (c == 't' || c == 'f' || c == '!' || c == '&' || c == '|') {
                st.push(c);
            } else if (c == ')') {
                bool seen_t = false, seen_f = false;
                // Pop smaller elements that are blocked from view
                while (!st.empty() && (st.top() == 't' || st.top() == 'f')) {
                    char val = st.top(); st.pop();
                    if (val == 't') seen_t = true;
                    if (val == 'f') seen_f = true;
                }
                char op = st.top(); st.pop();
                if (op == '!') st.push(seen_t ? 'f' : 't');
                else if (op == '&') st.push(seen_f ? 'f' : 't');
                else if (op == '|') st.push(seen_t ? 't' : 'f');
            }
        }
        std::cout << (st.top() == 't' ? "true" : "false") << std::endl;
    }
    return 0;
}