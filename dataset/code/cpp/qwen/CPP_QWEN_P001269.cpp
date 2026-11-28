#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    map<int, int> freq;
    for (int num : nums) freq[num]++;
    
    for (auto& p : freq) {
        if (p.second % k != 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    cout << "YES" << endl;
    return 0;
}
