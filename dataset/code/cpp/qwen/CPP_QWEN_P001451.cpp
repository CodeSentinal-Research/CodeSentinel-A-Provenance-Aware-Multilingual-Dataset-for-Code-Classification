#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    unordered_map<int, int> prefixXorCount;
    prefixXorCount[0] = 1;
    int currentXor = 0;
    long long count = 0;
    
    for (int num : nums) {
        currentXor ^= num;
        int needed = currentXor ^ k;
        if (prefixXorCount.find(needed) != prefixXorCount.end()) {
            count += prefixXorCount[needed];
        }
        prefixXorCount[currentXor]++;
    }
    
    cout << count << endl;
    return 0;
}
