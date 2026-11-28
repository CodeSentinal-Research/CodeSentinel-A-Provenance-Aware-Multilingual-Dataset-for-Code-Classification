#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s, p;
    cin >> s >> p;
    
    vector<int> pCount(26, 0);
    vector<int> sCount(26, 0);
    
    for (char c : p) pCount[c - 'a']++;
    
    vector<int> result;
    int left = 0;
    
    for (int right = 0; right < s.length(); ++right) {
        sCount[s[right] - 'a']++;
        
        if (right >= p.length()) {
            sCount[s[left] - 'a']--;
            left++;
        }
        
        if (sCount == pCount) {
            result.push_back(left);
        }
    }
    
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;
    
    return 0;
}
