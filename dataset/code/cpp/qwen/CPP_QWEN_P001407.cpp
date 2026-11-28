#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> changed(n);
    for (int i = 0; i < n; ++i) cin >> changed[i];
    
    if (n % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }
    
    sort(changed.begin(), changed.end());
    unordered_map<int, int> freq;
    for (int x : changed) freq[x]++;
    
    vector<int> original;
    for (int x : changed) {
        if (freq[x] == 0) continue;
        if (freq[2 * x] == 0) {
            cout << -1 << endl;
            return 0;
        }
        original.push_back(x);
        freq[x]--;
        freq[2 * x]--;
    }
    
    for (int x : original) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
