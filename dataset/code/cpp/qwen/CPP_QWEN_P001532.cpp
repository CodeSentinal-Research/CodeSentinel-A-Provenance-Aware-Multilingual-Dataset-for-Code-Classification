#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    
    unordered_map<char, int> freq;
    int left = 0;
    int maxLen = 0;
    
    for (int right = 0; right < s.length(); ++right) {
        freq[s[right]]++;
        
        while (freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0) freq.erase(s[left]);
            left++;
        }
        
        maxLen = max(maxLen, right - left + 1);
    }
    
    cout << maxLen << endl;
    return 0;
}
