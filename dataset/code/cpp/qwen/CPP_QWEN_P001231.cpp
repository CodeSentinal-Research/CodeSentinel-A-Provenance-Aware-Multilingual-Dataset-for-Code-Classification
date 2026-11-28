#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> g(n), s(m);
    for (int i = 0; i < n; ++i) cin >> g[i];
    for (int i = 0; i < m; ++i) cin >> s[i];
    
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    
    int i = 0, j = 0, count = 0;
    while (i < n && j < m) {
        if (g[i] <= s[j]) {
            count++;
            i++;
            j++;
        } else {
            j++;
        }
    }
    
    cout << count << endl;
    return 0;
}
