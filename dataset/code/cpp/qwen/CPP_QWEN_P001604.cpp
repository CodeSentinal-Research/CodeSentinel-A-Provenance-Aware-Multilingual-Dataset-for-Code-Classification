#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    unordered_map<long long, int> prefixCount;
    prefixCount[0] = 1;
    long long currentSum = 0;
    long long count = 0;
    
    for (int num : nums) {
        currentSum += num;
        if (prefixCount.find(currentSum - k) != prefixCount.end()) {
            count += prefixCount[currentSum - k];
        }
        prefixCount[currentSum]++;
    }
    
    cout << count << endl;
    return 0;
}
