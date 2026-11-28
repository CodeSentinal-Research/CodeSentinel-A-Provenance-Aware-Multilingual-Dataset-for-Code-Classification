#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    unordered_set<int> seen;
    int count = 0;
    
    for (int num : nums) {
        if (seen.count(num - k)) count++;
        if (k != 0 && seen.count(num + k)) count++;
        seen.insert(num);
    }
    
    cout << count << endl;
    return 0;
}
