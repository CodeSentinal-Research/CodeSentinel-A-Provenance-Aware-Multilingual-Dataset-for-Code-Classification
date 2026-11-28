#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<int> nums(n);
    vector<int> prefixOdd(n + 1, 0);
    
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        prefixOdd[i+1] = prefixOdd[i] + (nums[i] % 2 != 0 ? 1 : 0);
    }
    
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        cout << prefixOdd[R+1] - prefixOdd[L] << endl;
    }
    return 0;
}
