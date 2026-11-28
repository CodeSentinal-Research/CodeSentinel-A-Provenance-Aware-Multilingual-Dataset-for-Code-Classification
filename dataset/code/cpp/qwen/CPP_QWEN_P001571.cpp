#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    for (int i = 0; i <= n - k; ++i) {
        if (i > 0) cout << " ";
        cout << nums[i + k - 1] - nums[i];
    }
    cout << endl;
    
    return 0;
}
