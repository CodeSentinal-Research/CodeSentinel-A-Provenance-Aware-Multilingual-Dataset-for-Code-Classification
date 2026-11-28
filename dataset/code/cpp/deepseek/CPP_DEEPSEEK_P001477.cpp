#include <iostream>
#include <stack>

using namespace std;

bool backspaceCompare(string S, string T) {
    stack<char> s, t;
    for(int i = 0; i < S.size(); i++) {
        if(S[i] != '#') {
            s.push(S[i]);
        } else if(!s.empty()) {
            s.pop();
        }
    }
    for(int i = 0; i < T.size(); i++) {
        if(T[i] != '#') {
            t.push(T[i]);
        } else if(!t.empty()) {
            t.pop();
        }
    }
    while(!s.empty() && !t.empty()) {
        if(s.top() != t.top()) {
            return false;
        }
        s.pop();
        t.pop();
    }
    return s.empty() && t.empty();
}

int main() {
    string S, T;
    cin >> S >> T;
    if(backspaceCompare(S, T)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}