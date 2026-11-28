#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int res = 0, sign = 1;
    stack<int> st;
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            int num = 0;
            while (i < s.size() && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            i--;
            res += sign * num;
        } else if (s[i] == '+') {
            sign = 1;
        } else if (s[i] == '-') {
            sign = -1;
        } else if (s[i] == '(') {
            st.push(res);
            st.push(sign);
            res = 0;
            sign = 1;
        } else if (s[i] == ')') {
            res *= st.top(); st.pop();
            res += st.top(); st.pop();
        }
    }
    cout << res << endl;
    return 0;
}
