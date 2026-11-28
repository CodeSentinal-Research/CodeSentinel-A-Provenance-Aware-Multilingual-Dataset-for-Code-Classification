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
    
    string order;
    cin >> order;
    
    unordered_map<char, int> rank;
    for (int i = 0; i < order.length(); ++i) {
        rank[order[i]] = i;
    }
    
    for (int i = 1; i < n; ++i) {
        const string& w1 = words[i-1];
        const string& w2 = words[i];
        
        int j = 0;
        while (j < w1.length() && j < w2.length() && w1[j] == w2[j]) j++;
        
        if (j < w1.length() && j < w2.length()) {
            if (rank[w1[j]] > rank[w2[j]]) {
                cout << "NO" << endl;
                return 0;
            }
        } else if (w1.length() > w2.length()) {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    cout << "YES" << endl;
    return 0;
}
