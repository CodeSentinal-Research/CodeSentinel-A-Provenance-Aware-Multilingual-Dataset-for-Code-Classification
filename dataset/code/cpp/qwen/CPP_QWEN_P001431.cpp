#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int getMask(const string& s) {
    int mask = 0;
    for (char c : s) mask |= (1 << (c - 'a'));
    return mask;
}

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; ++i) cin >> words[i];
    
    unordered_map<int, int> freq;
    long long pairs = 0;
    
    for (const string& w : words) {
        int mask = getMask(w);
        pairs += freq[mask];
        freq[mask]++;
    }
    
    cout << pairs << endl;
    return 0;
}
