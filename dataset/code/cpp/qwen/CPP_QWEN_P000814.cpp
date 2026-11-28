#include <iostream>
#include <vector>
using namespace std;

// Simulated API
vector<bool> badVersions;
bool isBadVersion(int version) {
    return badVersions[version];
}

int main() {
    int n, firstBad;
    cin >> n >> firstBad;
    
    badVersions.assign(n + 1, false);
    for (int i = firstBad; i <= n; ++i) badVersions[i] = true;

    int low = 1, high = n;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (isBadVersion(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low << endl;
    return 0;
}
