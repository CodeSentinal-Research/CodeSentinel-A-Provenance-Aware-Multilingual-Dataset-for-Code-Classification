#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    if (n % 2 != 0) {
        cout << "NO" << endl;
        return 0;
    }
    
    unordered_map<int, int> modCount;
    for (int num : nums) {
        int rem = ((num % k) + k) % k;
        modCount[rem]++;
    }
    
    for (auto& p : modCount) {
        int r = p.first;
        int count = p.second;
        int complement = (k - r) % k;
        
        if (r == 0 || (k % 2 == 0 && r == k / 2)) {
            if (count % 2 != 0) {
                cout << "NO" << endl;
                return 0;
            }
        } else {
            if (modCount[complement] != count) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    
    cout << "YES" << endl;
    return 0;
}
