#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    vector<int> prefixXor(n);
    prefixXor[0] = nums[0];
    for (int i = 1; i < n; ++i) {
        prefixXor[i] = prefixXor[i-1] ^ nums[i];
    }
    
    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << " ";
        cout << prefixXor[i];
    }
    cout << endl;
    return 0;
}
