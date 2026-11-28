#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    vector<int> last(5, -1);
    long long ans = 0;
    
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'a') last[0] = i;
        else if (s[i] == 'e') last[1] = i;
        else if (s[i] == 'i') last[2] = i;
        else if (s[i] == 'o') last[3] = i;
        else if (s[i] == 'u') last[4] = i;
        
        int minLast = s.length();
        bool allPresent = true;
        for (int l : last) {
            if (l == -1) {
                allPresent = false;
                break;
            }
            minLast = min(minLast, l);
        }
        
        if (allPresent) {
            ans += (minLast + 1);
        }
    }
    
    cout << ans << endl;
    return 0;
}
