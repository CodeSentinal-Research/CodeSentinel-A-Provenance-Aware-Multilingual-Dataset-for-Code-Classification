#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int atMostK(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    long long count = 0;
    int left = 0;
    
    for (int right = 0; right < nums.size(); ++right) {
        freq[nums[right]]++;
        
        while (freq.size() > k) {
            freq[nums[left]]--;
            if (freq[nums[left]] == 0) freq.erase(nums[left]);
            left++;
        }
        
        count += (right - left + 1);
    }
    return count;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    cout << atMostK(nums, k) - atMostK(nums, k - 1) << endl;
    return 0;
}
