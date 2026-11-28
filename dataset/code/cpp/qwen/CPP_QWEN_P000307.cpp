#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main() {
    string s;
    cin >> s;
    int min_remove = 0;
    int open = 0;
    for (char c : s) {
        if (c == '(') open++;
        else if (c == ')') {
            if (open > 0) open--;
            else min_remove++;
        }
    }
    min_remove += open;
    
    queue<string> q;
    q.push(s);
    vector<string> res;
    bool found = false;
    while (!q.empty() && !found) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            string curr = q.front(); q.pop();
            int open = 0, close = 0;
            bool valid = true;
            for (char c : curr) {
                if (c == '(') open++;
                else if (c == ')') {
                    if (open > 0) open--;
                    else { valid = false; break; }
                }
            }
            if (valid && open == 0) {
                res.push_back(curr);
                found = true;
            }
            if (!found) {
                for (int j = 0; j < curr.size(); j++) {
                    if (curr[j] == '(' || curr[j] == ')') {
                        string next = curr.substr(0, j) + curr.substr(j + 1);
                        q.push(next);
                    }
                }
            }
        }
    }
    for (const string& r : res) cout << r << endl;
    return 0;
}
