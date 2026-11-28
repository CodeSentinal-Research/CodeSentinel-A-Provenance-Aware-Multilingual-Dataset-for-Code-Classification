#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
    string s;
    cin >> s;
    queue<char> q;
    string res = "";
    for (char c : s) {
        q.push(c);
        while (!q.empty()) {
            char front = q.front();
            bool found = false;
            queue<char> temp = q;
            while (!temp.empty()) {
                if (temp.front() == front) {
                    if (temp.size() == 1) {
                        found = true;
                        break;
                    }
                }
                temp.pop();
            }
            if (found) {
                res += front;
                q.pop();
            } else {
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}
