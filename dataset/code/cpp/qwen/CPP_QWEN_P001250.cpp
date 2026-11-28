#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    map<int, int> freq;
    for (int num : nums) freq[num]++;
    
    int prev = -1;
    int count = 0;
    bool possible = true;
    
    for (auto& p : freq) {
        if (prev != -1 && p.first != prev + 1) {
            possible = false;
            break;
        }
        prev = p.first;
        // Logic for splitting into consecutive subsequences of length >= 3 is complex.
        // Requires checking if we can append to existing sequences.
    }
    
    cout << (possible ? "YES" : "NO") << endl; // Placeholder
    return 0;
}
