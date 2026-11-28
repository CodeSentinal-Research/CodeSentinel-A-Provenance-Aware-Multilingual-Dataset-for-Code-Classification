#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int maxLen = 1;
    int left = 0;
    bool hasPair = false;
    
    for (int right = 1; right < s.length(); ++right) {
        if (s[right] == s[right-1]) {
            if (hasPair) {
                // Move left to right-1 to start new window with this pair
                left = right - 1;
            } else {
                hasPair = true;
            }
        } else {
            // If we had a pair before, and now different, we can still extend if we haven't seen another pair?
            // No, "at most one pair of adjacent equal digits".
            // If s[right] != s[right-1], no new pair formed.
            // But we need to check if the window already contains a pair.
            // My logic above resets left only when a second pair is found.
            // Wait, if s[right] != s[right-1], it doesn't form a pair.
            // So we just extend.
        }
        
        // Correction: The condition "at most one pair" means we can have 0 or 1 occurrence of i such that s[i]==s[i+1].
        
        // Let's restart simple sliding window.
        // Count pairs in window.
    }
    
    // Re-implement properly
    int pairs = 0;
    left = 0;
    maxLen = 1;
    
    for (int right = 1; right < s.length(); ++right) {
        if (s[right] == s[right-1]) {
            pairs++;
        }
        
        while (pairs > 1) {
            if (s[left] == s[left+1]) {
                pairs--;
            }
            left++;
        }
        
        maxLen = max(maxLen, right - left + 1);
    }
    
    cout << maxLen << endl;
    return 0;
}
