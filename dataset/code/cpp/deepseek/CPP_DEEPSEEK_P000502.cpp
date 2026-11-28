#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int evaluate(vector<string> &tokens) {
    stack<int> stk;
    for (string &s : tokens) {
        if (s.size() > 1 || isdigit(s[0])) {
            stk.push(stoi(s));
        } else {
            int op2 = stk.top(); stk.pop();
            int op1 = stk.top(); stk.pop();
            switch (s[0]) {
                case '+': stk.push(op1 + op2); break;
                case '-': stk.push(op1 - op2); break;
                case '*': stk.push(op1 * op2); break;
                case '/': stk.push(op1 / op2); break;
            }
        }
    }
    return stk.top();
}

int main() {
    vector<string> tokens = {"3", "5", "+", "4", "*", "2", "/"};
    cout << evaluate(tokens) << endl;
    return 0;
}