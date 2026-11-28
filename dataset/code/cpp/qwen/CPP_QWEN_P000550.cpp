#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int>& petrol, vector<int>& dist) {
    int n = petrol.size(), deficit = 0, balance = 0, start = 0;
    for (int i = 0; i < n; i++) {
        balance += petrol[i] - dist[i];
        if (balance < 0) { deficit += balance; start = i + 1; balance = 0; }
    }
    return (balance + deficit >= 0) ? start : -1;
}

int main() {
    int n; cin >> n;
    vector<int> p(n), d(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) cin >> d[i];
    cout << solve(p, d) << endl;
    return 0;
}
