#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i+1] = prefix[i] + nums[i];
    }
    
    int l, r;
    cin >> l >> r;
    cout << prefix[r+1] - prefix[l] << endl;
    
    return 0;
}
