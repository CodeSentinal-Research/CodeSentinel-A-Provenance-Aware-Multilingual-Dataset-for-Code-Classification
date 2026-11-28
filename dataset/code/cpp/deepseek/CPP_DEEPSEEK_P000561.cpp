#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

int main() {
    queue<char> q;
    unordered_set<char> seen;
    char c;
    while (cin >> c) {
        q.push(c);
        if (seen.find(c) != seen.end()) {
            seen.erase(c);
        } else {
            seen.insert(c);
        }
        while (!q.empty() && seen.find(q.front()) != seen.end()) {
            q.pop();
        }
        if (!q.empty()) {
            cout << q.front() << endl;
        } else {
            cout << '#' << endl;
        }
    }
    return 0;
}