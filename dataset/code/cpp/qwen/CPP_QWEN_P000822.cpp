#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    // Find position where x would be inserted
    int pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    
    int left = pos - 1;
    int right = pos;
    
    vector<int> result;
    while (result.size() < k) {
        if (left < 0) {
            result.push_back(arr[right++]);
        } else if (right >= n) {
            result.push_back(arr[left--]);
        } else {
            if (abs(arr[left] - x) <= abs(arr[right] - x)) {
                result.push_back(arr[left--]);
            } else {
                result.push_back(arr[right++]);
            }
        }
    }
    
    sort(result.begin(), result.end());
    for (size_t i = 0; i < result.size(); ++i) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << endl;
    return 0;
}
