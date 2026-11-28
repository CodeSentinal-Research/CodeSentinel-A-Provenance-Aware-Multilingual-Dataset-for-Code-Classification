#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> dominoes(n);
    for (int i = 0; i < n; ++i) {
        cin >> dominoes[i].first >> dominoes[i].second;
        if (dominoes[i].first > dominoes[i].second) 
            swap(dominoes[i].first, dominoes[i].second);
    }
    
    unordered_map<long long, int> freq;
    long long pairs = 0;
    
    for (auto& d : dominoes) {
        long long key = (long long)d.first * 100000 + d.second;
        pairs += freq[key];
        freq[key]++;
    }
    
    cout << pairs << endl;
    return 0;
}
