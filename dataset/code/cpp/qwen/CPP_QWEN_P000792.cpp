#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, goal;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    cin >> goal;
    
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;
    int currentSum = 0;
    int count = 0;
    
    for (int num : nums) {
        currentSum += num;
        if (prefixCount.find(currentSum - goal) != prefixCount.end()) {
            count += prefixCount[currentSum - goal];
        }
        prefixCount[currentSum]++;
    }
    
    cout << count << endl;
    return 0;
}
