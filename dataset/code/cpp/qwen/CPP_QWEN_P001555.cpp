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
    
    int maxVowels = 0;
    int currentVowels = 0;
    
    for (int i = 0; i < k; ++i) {
        if (isVowel(s[i])) currentVowels++;
    }
    maxVowels = currentVowels;
    
    for (int i = k; i < s.length(); ++i) {
        if (isVowel(s[i])) currentVowels++;
        if (isVowel(s[i-k])) currentVowels--;
        maxVowels = max(maxVowels, currentVowels);
    }
    
    cout << maxVowels << endl;
    return 0;
}
