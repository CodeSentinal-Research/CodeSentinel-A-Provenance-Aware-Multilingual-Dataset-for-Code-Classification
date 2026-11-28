#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    bool isPossible = false;
    int total_diff = 0;

    for (int i = 0; i < n; i++) {
        total_diff += arr[i];
        sum -= arr[i];
        if (abs(total_diff - sum) < abs(total_diff - total_diff)) {
            isPossible = true;
            break;
        }
    }

    if (isPossible) {
        cout << abs(total_diff - sum);
    } else {
        cout << abs(sum - total_diff);
    }

    return 0;
}