#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    string s;
    cin >> s;
    
    long long count = 0;
    int n = s.length();
    
    // For each position, if it's a vowel, it can be part of a substring.
    // We need substrings with ALL 5 vowels.
    
    // Optimized approach:
    // Track last occurrence of each vowel.
    // For each index i, if s[i] is a vowel, update its last occurrence.
    // The number of valid substrings ending at i is min(last_a, last_e, last_i, last_o, last_u) + 1.
    
    vector<int> last(5, -1); // a, e, i, o, u
    long long ans = 0;
    
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') last[0] = i;
        else if (s[i] == 'e') last[1] = i;
        else if (s[i] == 'i') last[2] = i;
        else if (s[i] == 'o') last[3] = i;
        else if (s[i] == 'u') last[4] = i;
        
        int minLast = n;
        for (int l : last) {
            if (l == -1) {
                minLast = -1;
                break;
            }
            minLast = min(minLast, l);
        }
        
        if (minLast != -1) {
            ans += (minLast + 1);
        }
    }
    
    cout << ans << endl;
    return 0;
}
