Here is the C++ code to solve the problem:

#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

string senate_party(string senate) {
    queue<int> r, d;
    for (int i = 0; i < senate.length(); i++) {
        if (senate[i] == 'R') r.push(i);
        else d.push(i);
    }

    while (!r.empty() && !d.empty()) {
        int r_index = r.front(); r.pop();
        int d_index = d.front(); d.pop();
        if (r_index < d_index) r.push(r_index + senate.length());
        else d.push(d_index + senate.length());
    }

    return r.empty() ? "Radiant" : "Dire";
}

int main() {
    string senate;
    cin >> senate;
    cout << senate_party(senate);
    return 0;
}

This code first creates two queues for radiant and dire senators. It then iterates through the senate string, pushing radiant and dire indexes to their respective queues. In the end, it checks which party will eventually win by comparing the current index of each senator. The senator who gets to the senate last wins the party.