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
    long long pairs = 0;
    
    for (int num : nums) {
        pairs += freq[num];
        freq[num]++;
    }
    
    cout << pairs << endl;
    return 0;
}
