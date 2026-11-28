#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;
    vector<long long> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    long long currentSum = 0;
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        currentSum += nums[i];
        if (currentSum >= x) {
            ans = i + 1;
            break;
        }
    }
    
    cout << ans << endl;
    return 0;
}
