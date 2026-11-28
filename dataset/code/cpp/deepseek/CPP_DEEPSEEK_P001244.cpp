Here is the C++ code:

#include <iostream>
#include <algorithm>
using namespace std;

bool reorganizeString(string s) {
    int n = s.size();
    int oddCount = 0;
    int maxCharCount = 0;

    int freq[26] = {0};
    for(int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
    }

    for(int i = 0; i < 26; i++) {
        if(freq[i] > 0 && freq[i] > maxCharCount) {
            maxCharCount = freq[i];
        }
        if(freq[i] > 0 && freq[i] % 2 != 0) {
            oddCount++;
        }
    }

    if(maxCharCount % 2 == 0 && oddCount == 0) {
        return true;
    } else if(maxCharCount % 2 == 1 && oddCount == 1) {
        return true;
    } else {
        return false;
    }
}

int main() {
    string s;
    cin >> s;

    if(reorganizeString(s)) {
        cout << "POSSIBLE" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}

This code will read a string as input, then check if it's possible to rearrange the characters in such a way that no two adjacent characters are the same. If it is, it will print "POSSIBLE", otherwise it will print "IMPOSSIBLE".