#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;

    int vowels[26] = {0};
    int left = 0, right = 0, maxLen = 0, vowelCount = 0;

    while (right < s.size()) {
        vowels[s[right] - 'a']++;
        if (vowels[s[right] - 'a'] == 1) {
            vowelCount++;
        }
        while (vowelCount > k) {
            vowels[s[left] - 'a']--;
            if (vowels[s[left] - 'a'] == 0) {
                vowelCount--;
            }
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
        right++;
    }

    cout << maxLen;

    return 0;
}