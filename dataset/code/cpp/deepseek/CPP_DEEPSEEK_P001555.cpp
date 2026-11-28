#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    
    set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    unordered_set<char> vowels_set(vowels.begin(), vowels.end());
    
    int max_vowels = 0;
    int current_vowels = 0;
    for (int i = 0; i < s.length(); i++) {
        if (vowels_set.count(s[i])) {
            current_vowels++;
            max_vowels = max(max_vowels, current_vowels);
        } else {
            current_vowels = 0;
        }
    }
    
    cout << max_vowels;
    return 0;
}