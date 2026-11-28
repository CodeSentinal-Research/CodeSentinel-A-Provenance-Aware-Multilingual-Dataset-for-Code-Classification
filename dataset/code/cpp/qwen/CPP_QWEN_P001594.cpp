#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    vector<long long> prefix(n);
    prefix[0] = nums[0];
    for (int i = 1; i < n; ++i) {
        prefix[i] = prefix[i-1] + nums[i];
    }
    
    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << " ";
        cout << prefix[i];
    }
    cout << endl;
    
    return 0;
}
