#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool backspaceCompare(string s, string t) {
    stack<char> s1, s2;
    for (char c : s) {
        if (c != '#') {
            s1.push(c);
        } else if (!s1.empty()) {
            s1.pop();
        }
    }
    
    for (char c : t) {
        if (c != '#') {
            s2.push(c);
        } else if (!s2.empty()) {
            s2.pop();
        }
    }
    
    while (!s1.empty()) {
        if (s1.top() != s2.top()) {
            return false;
        }
        s1.pop();
        s2.pop();
    }
    
    return s1.empty() && s2.empty();
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << (backspaceCompare(s, t) ? "true" : "false");
    return 0;
}

This C++ program first processes both strings by pushing non-backspace characters onto a stack. Then, it compares the processed strings by popping characters from both stacks. If they are equal, it continues to pop characters from both stacks until all characters have been processed. If at any point the processed strings are not equal or one of them is not empty, it returns false. If both stacks are empty at the end, it returns true.