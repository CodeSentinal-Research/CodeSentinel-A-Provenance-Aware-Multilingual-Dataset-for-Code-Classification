#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    unordered_set<int> seen;
    for (int num : nums) {
        if (seen.count(2 * num) || (num % 2 == 0 && seen.count(num / 2))) {
            cout << "YES" << endl;
            return 0;
        }
        seen.insert(num);
    }
    
    cout << "NO" << endl;
    return 0;
}
