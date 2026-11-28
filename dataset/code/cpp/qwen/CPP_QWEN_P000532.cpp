#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int>& tickets, int k) {
    int time = 0;
    for (int i = 0; i < tickets.size(); i++) {
        if (i <= k) time += min(tickets[i], tickets[k]);
        else time += min(tickets[i], tickets[k] - 1);
    }
    return time;
}

int main() {
    int n; cin >> n;
    vector<int> t(n);
    for(int i = 0; i < n; i++) cin >> t[i];
    int k; cin >> k;
    cout << solve(t, k) << endl;
    return 0;
}
