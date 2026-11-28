#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    vector<int> last(3, -1); // a, b, c
    long long count = 0;
    
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'a') last[0] = i;
        else if (s[i] == 'b') last[1] = i;
        else if (s[i] == 'c') last[2] = i;
        
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
            count += (minLast + 1);
        }
    }
    
    cout << count << endl;
    return 0;
}
