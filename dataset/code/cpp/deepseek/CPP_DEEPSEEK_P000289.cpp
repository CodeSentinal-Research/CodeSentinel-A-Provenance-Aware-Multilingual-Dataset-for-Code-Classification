#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int longestRepeatingCharacterReplacement(string s, int k) {
    int n = s.length();
    int left = 0, right = 0;
    int maxFreq = 0, maxLength = 0;
    int charCount[26] = {0};

    while (right < n) {
        charCount[s[right] - 'A']++;
        maxFreq = max(maxFreq, charCount[s[right] - 'A']);
        right++;

        if (right - left > maxFreq + k) {
            charCount[s[left] - 'A']--;
            left++;
        }

        maxLength = max(maxLength, right - left);
    }

    return maxLength;
}

int main() {
    string s;
    int k;

    cout << "Enter the string: ";
    cin >> s;

    cout << "Enter the number of replacements: ";
    cin >> k;

    cout << "Length of the longest substring: " << longestRepeatingCharacterReplacement(s, k) << endl;

    return 0;
}