#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    vector<int> prefixMod(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixMod[i+1] = prefixMod[i] + (nums[i] % k == 0 ? 1 : 0);
    }
    
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << prefixMod[r+1] - prefixMod[l] << endl;
    }
    
    return 0;
}
