#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    
    int minLen = INT_MAX;
    int startIdx = -1;
    
    vector<int> required(256, 0);
    vector<int> formed(256, 0);
    int neededChars = 0;
    
    for (char c : t) {
        if (required[c] == 0) neededChars++;
        required[c]++;
    }
    
    int left = 0, matched = 0;
    
    for (int right = 0; right < s.length(); ++right) {
        char c = s[right];
        formed[c]++;
        
        if (required[c] > 0 && formed[c] == required[c]) {
            matched++;
        }
        
        while (left <= right && matched == neededChars) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                startIdx = left;
            }
            
            char leftChar = s[left];
            formed[leftChar]--;
            if (required[leftChar] > 0 && formed[leftChar] < required[leftChar]) {
                matched--;
            }
            left++;
        }
    }
    
    if (startIdx == -1) cout << "" << endl;
    else cout << s.substr(startIdx, minLen) << endl;
    
    return 0;
}
