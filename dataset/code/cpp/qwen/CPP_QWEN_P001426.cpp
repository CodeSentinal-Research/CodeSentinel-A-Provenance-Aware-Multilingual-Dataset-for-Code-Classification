#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    unordered_map<int, int> freq;
    for (int num : nums) freq[num]++;
    
    int lucky = -1;
    for (auto& p : freq) {
        if (p.first == p.second) {
            lucky = max(lucky, p.first);
        }
    }
    
    cout << lucky << endl;
    return 0;
}
