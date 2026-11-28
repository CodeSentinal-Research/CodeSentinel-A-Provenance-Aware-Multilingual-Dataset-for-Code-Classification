#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

int evaluate(string expression) {
    stack<int> values;
    stack<char> ops;

    for(int i = 0; i < expression.length(); i++) {
        if(expression[i] == '(') {
            ops.push(expression[i]);
        } else if(isdigit(expression[i])) {
            int x = 0;
            while(i < expression.length() && isdigit(expression[i])) {
                x = (x*10) + (expression[i]-'0');
                i++;
            }
            i--;
            values.push(x);
        } else if(expression[i] == ')') {
            while(!ops.empty() && ops.top() != '(') {
                int right = values.top(); values.pop();
                int left = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                switch(op) {
                    case '+': left += right; break;
                    case '-': left -= right; break;
                    case '*': left *= right; break;
                    case '/': left /= right; break;
                }
                values.push(left);
            }
            ops.pop();
        } else {
            while(!ops.empty() && ops.top() != '(') {
                char op = ops.top(); ops.pop();
                int right = values.top(); values.pop();
                int left = values.top(); values.pop();
                switch(op) {
                    case '+': left += right; break;
                    case '-': left -= right; break;
                    case '*': left *= right; break;
                    case '/': left /= right; break;
                }
                values.push(left);
            }
            ops.push(expression[i]);
        }
    }

    while(!ops.empty()) {
        char op = ops.top(); ops.pop();
        int right = values.top(); values.pop();
        int left = values.top(); values.pop();
        switch(op) {
            case '+': left += right; break;
            case '-': left -= right; break;
            case '*': left *= right; break;
            case '/': left /= right; break;
        }
        values.push(left);
    }

    return values.top();
}

int main() {
    string expression;
    cin >> expression;
    cout << evaluate(expression) << endl;
    return 0;
}
This program uses a stack to handle the input expression. It first processes the input string to extract the numbers and operators and pushes them into the respective stacks. Then, it processes the operators by popping the top elements from the stacks, performing the operation and pushing the result back into the stack. In the end, the top element of the stack will be the result.