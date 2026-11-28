#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    unordered_map<int, int> freq;
    for(int num : nums) {
        freq[num]++;
    }
    
    int max_freq = -1, max_lucky = -1;
    for(auto pair : freq) {
        if(pair.first == pair.second && pair.first > max_lucky) {
            max_lucky = pair.first;
            max_freq = pair.second;
        }
    }
    
    cout << max_lucky << endl;
    return 0;
}