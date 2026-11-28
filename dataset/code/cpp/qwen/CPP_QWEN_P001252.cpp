#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> pairs(n);
    for (int i = 0; i < n; ++i) {
        cin >> pairs[i].first >> pairs[i].second;
    }
    
    sort(pairs.begin(), pairs.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        return a.second < b.second;
    });
    
    int chainLen = 1;
    int lastEnd = pairs[0].second;
    
    for (int i = 1; i < n; ++i) {
        if (pairs[i].first > lastEnd) {
            chainLen++;
            lastEnd = pairs[i].second;
        }
    }
    
    cout << chainLen << endl;
    return 0;
}
