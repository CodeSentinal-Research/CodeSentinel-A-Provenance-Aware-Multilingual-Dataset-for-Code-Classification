#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    
    int maxLen = 0;
    int vowels = 0;
    int left = 0;
    
    for (int right = 0; right < s.length(); ++right) {
        if (isVowel(s[right])) vowels++;
        
        while (vowels > k) {
            if (isVowel(s[left])) vowels--;
            left++;
        }
        
        maxLen = max(maxLen, right - left + 1);
    }
    
    cout << maxLen << endl;
    return 0;
}
