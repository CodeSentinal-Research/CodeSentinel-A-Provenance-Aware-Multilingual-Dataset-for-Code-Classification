#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    
    // Max consecutive T or F
    // Solve for T, solve for F, take max
    
    auto solve = [&](char target) -> int {
        vector<int> count(2, 0); // 0 for other, 1 for target
        int left = 0;
        int maxLen = 0;
        for (int right = 0; right < s.length(); ++right) {
            if (s[right] == target) count[1]++;
            else count[0]++;
            
            while (count[0] > k) {
                if (s[left] == target) count[1]--;
                else count[0]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    };
    
    cout << max(solve('T'), solve('F')) << endl;
    return 0;
}
