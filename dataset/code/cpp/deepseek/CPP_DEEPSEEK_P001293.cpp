#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long maxProduct(vector<int> arr, int k) {
    sort(arr.begin(), arr.end());
    long long result = 1;
    for (int i = 0; i < arr.size(); i++) {
        result = (result * arr[i]) % 1000000007;
    }
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << maxProduct(arr, k);
    return 0;
}