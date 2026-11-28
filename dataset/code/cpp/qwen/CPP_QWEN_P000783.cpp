#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<int> nums(n);
    vector<int> prefixEven(n + 1, 0);
    
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        prefixEven[i+1] = prefixEven[i] + (nums[i] % 2 == 0 ? 1 : 0);
    }
    
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        cout << prefixEven[R+1] - prefixEven[L] << endl;
    }
    return 0;
}
