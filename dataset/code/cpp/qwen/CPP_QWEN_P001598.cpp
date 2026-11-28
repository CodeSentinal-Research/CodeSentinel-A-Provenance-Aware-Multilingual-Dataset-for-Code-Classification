#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    vector<int> prefixEven(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixEven[i+1] = prefixEven[i] + (nums[i] % 2 == 0 ? 1 : 0);
    }
    
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << prefixEven[r+1] - prefixEven[l] << endl;
    }
    
    return 0;
}
