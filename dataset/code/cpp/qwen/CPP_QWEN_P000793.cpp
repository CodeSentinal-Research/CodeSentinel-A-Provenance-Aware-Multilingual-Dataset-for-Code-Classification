#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    cin >> k;
    
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;
    int oddCount = 0;
    int count = 0;
    
    for (int num : nums) {
        if (num % 2 != 0) oddCount++;
        if (prefixCount.find(oddCount - k) != prefixCount.end()) {
            count += prefixCount[oddCount - k];
        }
        prefixCount[oddCount]++;
    }
    
    cout << count << endl;
    return 0;
}
