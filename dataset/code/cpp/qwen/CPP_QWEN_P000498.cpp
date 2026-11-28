#include <iostream>
#include <string>
#include <stack>
using namespace std;
int calculate(string s) {
    stack<int> st;
    int num = 0, res = 0, sign = 1;
    for(char c : s) {
        if(isdigit(c)) { num = num*10 + (c-'0'); }
        else if(c == '+') { res += sign * num; num = 0; sign = 1; }
        else if(c == '-') { res += sign * num; num = 0; sign = -1; }
        else if(c == '(') { st.push(res); st.push(sign); res = 0; sign = 1; }
        else if(c == ')') { res += sign * num; num = 0; sign = st.top(); st.pop(); res *= sign; res += st.top(); st.pop(); }
    }
    res += sign * num;
    return res;
}
int main() {
    string s; getline(cin, s);
    cout << calculate(s) << endl;
    return 0;
}
