#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; ++i) cin >> words[i];
    
    unordered_map<string, int> freq;
    for (const string& w : words) freq[w]++;
    
    long long length = 0;
    bool hasOddCenter = false;
    
    for (auto& p : freq) {
        string w = p.first;
        string rev = w;
        reverse(rev.begin(), rev.end());
        
        if (w == rev) {
            length += (p.second / 2) * 4;
            if (p.second % 2 == 1) hasOddCenter = true;
        } else if (w < rev) { // Process pair once
            int pairs = min(p.second, freq.count(rev) ? freq[rev] : 0);
            length += pairs * 4;
        }
    }
    
    if (hasOddCenter) length += 2;
    
    cout << length << endl;
    return 0;
}
