#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<string> removeInvalidParentheses(string s) {
    unordered_set<string> resSet;
    queue<pair<string, int>> q;
    q.push({s, 0});
    while (!q.empty()) {
        string cur = q.front().first;
        int step = q.front().second;
        q.pop();
        if (step == s.size()) {
            resSet.insert(cur);
        } else {
            for (int i = 0; i < cur.size(); ++i) {
                if (cur[i] == '(' || cur[i] == ')') {
                    string next = cur.substr(0, i) + cur.substr(i + 1, cur.size() - i - 1);
                    if (resSet.find(next) == resSet.end()) {
                        q.push({next, step + 1});
                    }
                }
            }
        }
    }
    vector<string> res(resSet.begin(), resSet.end());
    sort(res.begin(), res.end());
    return res;
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
This C++ code uses the breadth-first search algorithm to find all possible valid strings from a given string. It uses a queue to keep track of the strings to be processed, and a set to store the valid strings. Each string is processed in the order of the BFS, so we start with the initial string and then gradually add more strings to the queue. For each string, we generate all its possible next strings by removing one character at a time, and add them to the queue if they are not in the set of valid strings.