#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    vector<bool> present(n + 1, false);
    for (int num : nums) {
        if (num > 0 && num <= n) present[num] = true;
    }
    
    for (int i = 1; i <= n; ++i) {
        if (!present[i]) {
            cout << i << endl;
            return 0;
        }
    }
    
    cout << n + 1 << endl;
    return 0;
}
