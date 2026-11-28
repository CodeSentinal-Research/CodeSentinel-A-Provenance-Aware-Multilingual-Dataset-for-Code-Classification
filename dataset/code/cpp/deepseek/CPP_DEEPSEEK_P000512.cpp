#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> stk;
    int i = 0, j = 0;
    while (i < pushed.size() || !stk.empty()) {
        if (stk.empty() || stk.top() != pushed[i]) {
            stk.push(pushed[i++]);
        } else {
            if (stk.top() == popped[j]) {
                stk.pop();
                j++;
            }
        }
    }
    while (!stk.empty()) {
        if (stk.top() != popped[j]) {
            return false;
        }
        stk.pop();
        j++;
    }
    return true;
}

int main() {
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped = {4, 5, 3, 2, 1};
    cout << validateStackSequences(pushed, popped);
    return 0;
}