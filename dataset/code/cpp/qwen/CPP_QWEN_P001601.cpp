#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    // Prefix sum of zeros
    vector<int> prefixZero(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixZero[i+1] = prefixZero[i] + (nums[i] == 0 ? 1 : 0);
    }
    
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << prefixZero[r+1] - prefixZero[l] << endl;
    }
    return 0;
}
