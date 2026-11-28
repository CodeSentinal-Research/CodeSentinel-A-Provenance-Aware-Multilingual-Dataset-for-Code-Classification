#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    unordered_map<int, int> modCount;
    modCount[0] = 1;
    long long currentSum = 0;
    int count = 0;
    
    for (int num : nums) {
        currentSum += num;
        int mod = ((currentSum % k) + k) % k;
        if (modCount.find(mod) != modCount.end()) {
            count += modCount[mod];
        }
        modCount[mod]++;
    }
    
    cout << count << endl;
    return 0;
}
