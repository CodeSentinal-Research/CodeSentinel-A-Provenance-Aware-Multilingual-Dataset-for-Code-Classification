#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    vector<int> freq(26, 0);
    for (char c : s) freq[c-'a']++;
    
    sort(freq.rbegin(), freq.rend());
    
    int deletions = 0;
    for (int i = 1; i < 26; ++i) {
        while (freq[i] > 0 && freq[i] >= freq[i-1]) {
            freq[i]--;
            deletions++;
        }
    }
    
    cout << deletions << endl;
    return 0;
}
