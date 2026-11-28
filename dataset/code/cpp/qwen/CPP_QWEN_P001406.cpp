#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, key;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    cin >> key;
    
    unordered_map<int, int> nextFreq;
    for (int i = 0; i < n - 1; ++i) {
        if (nums[i] == key) {
            nextFreq[nums[i+1]]++;
        }
    }
    
    int maxFreq = 0;
    int result = -1;
    for (auto& p : nextFreq) {
        if (p.second > maxFreq || (p.second == maxFreq && p.first < result)) {
            maxFreq = p.second;
            result = p.first;
        }
    }
    
    cout << result << endl;
    return 0;
}
