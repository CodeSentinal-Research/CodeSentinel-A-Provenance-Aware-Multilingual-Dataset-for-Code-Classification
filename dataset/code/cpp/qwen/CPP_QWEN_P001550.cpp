#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    for (int i = 0; i <= n - k; ++i) {
        long long sum = 0;
        for (int j = i; j < i + k - 1; ++j) {
            sum += abs(nums[j+1] - nums[j]);
        }
        if (i > 0) cout << " ";
        cout << sum;
    }
    cout << endl;
    
    return 0;
}
