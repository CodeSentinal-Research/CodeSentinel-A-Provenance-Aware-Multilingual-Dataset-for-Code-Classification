#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<int> nums(n);
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        prefix[i+1] = prefix[i] ^ nums[i];
    }
    
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        cout << (prefix[R+1] ^ prefix[L]) << endl;
    }
    return 0;
}
