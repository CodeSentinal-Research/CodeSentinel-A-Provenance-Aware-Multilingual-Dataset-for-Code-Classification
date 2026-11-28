#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i+1] = prefix[i] + (s[i] - 'a' + 1);
    }
    
    for (int i = 1; i <= n; ++i) {
        if (i > 1) cout << " ";
        cout << prefix[i];
    }
    cout << endl;
    return 0;
}
