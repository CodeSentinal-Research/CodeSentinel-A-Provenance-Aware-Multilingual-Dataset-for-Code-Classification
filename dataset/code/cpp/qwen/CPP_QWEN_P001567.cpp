#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    unordered_set<int> distinctSet;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        distinctSet.insert(nums[i]);
    }
    
    int totalDistinct = distinctSet.size();
    long long count = 0;
    
    unordered_map<int, int> windowFreq;
    int matched = 0;
    int left = 0;
    
    for (int right = 0; right < n; ++right) {
        windowFreq[nums[right]]++;
        if (windowFreq[nums[right]] == 1) matched++;
        
        while (matched == totalDistinct) {
            count += (n - right);
            windowFreq[nums[left]]--;
            if (windowFreq[nums[left]] == 0) matched--;
            left++;
        }
    }
    
    cout << count << endl;
    return 0;
}
