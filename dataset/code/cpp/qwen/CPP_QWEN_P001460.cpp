#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    unordered_map<int, int> prefixXorCount;
    prefixXorCount[0] = 1;
    int currentXor = 0;
    long long count = 0;
    
    for (int num : nums) {
        currentXor ^= num;
        count += prefixXorCount[currentXor];
        prefixXorCount[currentXor]++;
    }
    
    cout << count << endl;
    return 0;
}
