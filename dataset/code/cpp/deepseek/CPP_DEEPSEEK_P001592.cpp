#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int prefixSum = 0;
    int earliestPrefixWithSumAtLeastX = -1;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];
        if (prefixSum >= x) {
            earliestPrefixWithSumAtLeastX = i + 1;
            break;
        }
    }

    if (earliestPrefixWithSumAtLeastX == -1) {
        cout << -1 << endl;
    } else {
        cout << earliestPrefixWithSumAtLeastX << endl;
    }

    return 0;
}