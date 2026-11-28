#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i+1] = prefix[i] + nums[i];
    }
    
    int ans = -1;
    for (int i = 1; i <= n; ++i) {
        if (prefix[i] >= x) {
            ans = i - 1; // 0-indexed
            break;
        }
    }
    
    cout << ans << endl;
    return 0;
}
