#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
using namespace std;

bool isValid(string s) {
    int count = 0;
    for (char c : s) {
        if (c == '(') count++;
        else if (c == ')') count--;
        if (count < 0) return false;
    }
    return count == 0;
}

void removeInvalidParenthesesHelper(string s, set<string>& result) {
    queue<string> q;
    set<string> visited;
    q.push(s);
    visited.insert(s);
    bool found = false;
    
    while (!q.empty()) {
        string curr = q.front(); q.pop();
        
        if (isValid(curr)) {
            result.insert(curr);
            found = true;
        }
        
        if (found) continue; // Only process min removal level
        
        for (int i = 0; i < curr.length(); ++i) {
            if (curr[i] != '(' && curr[i] != ')') continue;
            string next = curr.substr(0, i) + curr.substr(i + 1);
            if (visited.find(next) == visited.end()) {
                q.push(next);
                visited.insert(next);
            }
        }
    }
}

int main() {
    string s;
    cin >> s;
    set<string> result;
    removeInvalidParenthesesHelper(s, result);
    
    for (const string& valid : result) {
        cout << valid << endl;
    }
    return 0;
}
