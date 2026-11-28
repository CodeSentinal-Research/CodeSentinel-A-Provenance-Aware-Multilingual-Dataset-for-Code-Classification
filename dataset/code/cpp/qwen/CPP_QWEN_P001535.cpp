#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    
    vector<int> count(26, 0);
    int maxCount = 0;
    int left = 0;
    int maxLen = 0;
    
    for (int right = 0; right < s.length(); ++right) {
        count[s[right] - 'A']++;
        maxCount = max(maxCount, count[s[right] - 'A']);
        
        while (right - left + 1 - maxCount > k) {
            count[s[left] - 'A']--;
            left++;
        }
        
        maxLen = max(maxLen, right - left + 1);
    }
    
    cout << maxLen << endl;
    return 0;
}
