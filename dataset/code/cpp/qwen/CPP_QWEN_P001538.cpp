#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    
    if (s1.length() > s2.length()) swap(s1, s2);
    
    vector<int> s1Count(26, 0);
    vector<int> s2Count(26, 0);
    
    for (char c : s1) s1Count[c - 'a']++;
    
    int left = 0;
    for (int right = 0; right < s2.length(); ++right) {
        s2Count[s2[right] - 'a']++;
        
        if (right >= s1.length()) {
            s2Count[s2[left] - 'a']--;
            left++;
        }
        
        if (s1Count == s2Count) {
            cout << "YES" << endl;
            return 0;
        }
    }
    
    cout << "NO" << endl;
    return 0;
}
