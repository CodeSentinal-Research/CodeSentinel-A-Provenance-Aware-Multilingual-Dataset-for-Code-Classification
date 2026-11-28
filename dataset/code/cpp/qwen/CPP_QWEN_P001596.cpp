#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    vector<int> prefixPositive(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixPositive[i+1] = prefixPositive[i] + (nums[i] > 0 ? 1 : 0);
    }
    
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << prefixPositive[r+1] - prefixPositive[l] << endl;
    }
    
    return 0;
}
