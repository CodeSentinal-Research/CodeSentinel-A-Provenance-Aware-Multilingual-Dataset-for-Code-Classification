#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canBeTyped(string s, string t) {
    int count1[26] = {0}, count2[26] = {0};
    for(char c: s) count1[c - 'a']++;
    for(char c: t) count2[c - 'a']++;
    for(int i = 0; i < 26; i++) {
        if(count1[i] > count2[i]) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for(int i = 0; i < n; i++) {
        cin >> words[i];
    }
    sort(words.begin(), words.end());
    for(string s: words) {
        bool flag = true;
        for(string t: words) {
            if(s != t && !canBeTyped(s, t)) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << s << "\n";
        }
    }
    return 0;
}