#include <iostream>
#include <string>
using namespace std;

int solve(string s) {
    int collisions = 0;
    bool hasR = false, hasL = false;
    for (char c : s) {
        if (c == 'R') hasR = true;
        else if (c == 'L') {
            if (hasR) collisions += 2;
            else collisions += 1;
        } else if (c == 'S') {
            if (hasR) collisions += 1;
        }
    }
    return collisions;
}

int main() {
    string s; cin >> s;
    cout << solve(s) << endl;
    return 0;
}
