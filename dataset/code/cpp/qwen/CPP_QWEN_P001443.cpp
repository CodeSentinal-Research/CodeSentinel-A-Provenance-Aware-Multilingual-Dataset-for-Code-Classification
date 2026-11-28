#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int getMask(const string& s) {
    int mask = 0;
    for (char c : s) mask |= (1 << (c - 'a'));
    return mask;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<string> startWords(n), targetWords(m);
    for (int i = 0; i < n; ++i) cin >> startWords[i];
    for (int i = 0; i < m; ++i) cin >> targetWords[i];
    
    unordered_map<int, int> startMasks;
    for (const string& w : startWords) {
        startMasks[getMask(w)]++;
    }
    
    int count = 0;
    for (const string& w : targetWords) {
        int mask = getMask(w);
        for (int i = 0; i < 26; ++i) {
            if (mask & (1 << i)) {
                int prevMask = mask ^ (1 << i);
                if (startMasks.count(prevMask)) {
                    count++;
                    break;
                }
            }
        }
    }
    
    cout << count << endl;
    return 0;
}
