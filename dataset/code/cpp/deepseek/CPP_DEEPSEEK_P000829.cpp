#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool feasible(vector<int> &weights, int mid, int days) {
    int sum = 0, count = 1;
    for (int i = 0; i < weights.size(); i++) {
        if (weights[i] > mid) return false;
        if (sum + weights[i] > mid) {
            sum = weights[i];
            count++;
        } else {
            sum += weights[i];
        }
    }
    if (count > days) return false;
    return true;
}

int binarySearch(vector<int> &weights, int days) {
    int low = 1, high = weights[0];
    for (int i = 1; i < weights.size(); i++) {
        if (weights[i] > high) high = weights[i];
    }
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (feasible(weights, mid, days)) high = mid;
        else low = mid + 1;
    }
    return low;
}

int main() {
    int n, day;
    cin >> n >> day;
    vector<int> weights(n);
    for (int i = 0; i < n; i++) cin >> weights[i];
    cout << binarySearch(weights, day);
    return 0;
}