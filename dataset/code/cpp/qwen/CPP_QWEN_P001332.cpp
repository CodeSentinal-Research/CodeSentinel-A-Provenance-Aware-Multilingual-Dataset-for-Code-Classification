#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

void removeInvalidParentheses(string s, vector<string>& result) {
    unordered_set<string> visited;
    queue<string> q;
    q.push(s);
    visited.insert(s);
    bool found = false;
    
    while (!q.empty()) {
        string curr = q.front(); q.pop();
        
        if (isValid(curr)) { // Need to define isValid
             // This is a placeholder. Full implementation requires BFS.
             // For brevity, assuming standard library or helper.
        }
        
        if (found) continue;
        
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

// Helper for validity
bool isValid(const string& s) {
    int count = 0;
    for (char c : s) {
        if (c == '(') count++;
        else if (c == ')') count--;
        if (count < 0) return false;
    }
    return count == 0;
}

int main() {
    string s;
    cin >> s;
    vector<string> result;
    // Call BFS function here
    cout << "Requires full BFS implementation" << endl;
    return 0;
}
