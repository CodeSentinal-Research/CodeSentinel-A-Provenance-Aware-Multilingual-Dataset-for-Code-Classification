#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool canRun(const vector<long long>& batteries, int n, long long minutes) {
    long long totalPower = 0;
    for (long long b : batteries) {
        totalPower += min(b, minutes);
    }
    return totalPower >= n * minutes;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> batteries(m);
    for (int i = 0; i < m; ++i) cin >> batteries[i];
    
    long long low = 1;
    long long high = accumulate(batteries.begin(), batteries.end(), 0LL) / n;
    
    while (low < high) {
        long long mid = low + (high - low + 1) / 2;
        if (canRun(batteries, n, mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    cout << low << endl;
    return 0;
}
