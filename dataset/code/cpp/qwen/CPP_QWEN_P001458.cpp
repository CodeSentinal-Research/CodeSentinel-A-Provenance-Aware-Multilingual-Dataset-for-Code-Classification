#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    
    vector<vector<bool>> isPal(n, vector<bool>(n, false));
    unordered_set<string> pals;
    
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            if (len == 1) {
                isPal[i][j] = true;
            } else if (len == 2) {
                isPal[i][j] = (s[i] == s[j]);
            } else {
                isPal[i][j] = (s[i] == s[j] && isPal[i+1][j-1]);
            }
            
            if (isPal[i][j]) {
                pals.insert(s.substr(i, len));
            }
        }
    }
    
    cout << pals.size() << endl;
    return 0;
}
