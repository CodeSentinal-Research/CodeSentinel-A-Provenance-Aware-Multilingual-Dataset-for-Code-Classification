#include <iostream>
#include <string>
#include <vector>
#include <stack>
int main() {
    int n;
    if (std::cin >> n) {
        std::stack<long long> st;
        for (int i = 0; i < n; i++) {
            std::string s;
            std::cin >> s;
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                if (s == "+") st.push(a + b);
                else if (s == "-") st.push(a - b);
                else if (s == "*") st.push(a * b);
                else if (s == "/") st.push(a / b);
            } else {
                st.push(std::stoll(s));
            }
        }
        std::cout << st.top() << std::endl;
    }
    return 0;
}