Here is the C++ code that solves the problem:

#include <iostream>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

vector<string> removeInvalidParentheses(string s) {
    unordered_set<string> seen;
    queue<string> todo;
    todo.push(s);
    seen.insert(s);
    while (!todo.empty()) {
        string t = todo.front();
        todo.pop();
        if (is_valid(t)) {
            cout << t << endl;
        } else {
            for (int i = 0; i < t.size(); ++i) {
                if (is_match(t[i])) {
                    string next = t.substr(0, i) + t.substr(i + 1);
                    if (!seen.count(next)) {
                        seen.insert(next);
                        todo.push(next);
                    }
                }
            }
        }
    }
}

int main() {
    string s;
    cin >> s;
    vector<string> res = removeInvalidParentheses(s);
    for (string str : res) {
        cout << str << endl;
    }
    return 0;
}

In this code, we use a Breadth-First Search (BFS) strategy to find all valid strings. We use a queue to store strings that have not been processed yet. We also use a set to store strings that have been processed. In each iteration of the loop, we process all strings in the queue. For each string, we remove all invalid parentheses, and for each new string that is valid, we add it to the queue and to the set.

The `is_valid` and `is_match` functions are assumed to be defined elsewhere in the code. They should return true if a string is valid and false otherwise.