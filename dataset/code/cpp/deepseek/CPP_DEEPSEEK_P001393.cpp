#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

bool continuousSubarraySum(int arr[], int n, int k) {
    unordered_map<int, int> um;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum % k == 0) {
            return true;
        }
        if (um.find(sum % k) != um.end()) {
            if (i - um[sum % k] >= 2) {
                return true;
            }
        }
        else {
            um[sum % k] = i;
        }
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (continuousSubarraySum(arr, n, k)) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}