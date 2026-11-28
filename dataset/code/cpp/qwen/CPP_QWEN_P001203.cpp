#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> envelopes(n);
    for (int i = 0; i < n; ++i) {
        cin >> envelopes[i].first >> envelopes[i].second;
    }
    
    // Sort by width ascending, then height descending if widths are equal
    sort(envelopes.begin(), envelopes.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });
    
    // Find LIS of heights
    vector<int> tails;
    for (auto& e : envelopes) {
        int h = e.second;
        auto it = lower_bound(tails.begin(), tails.end(), h);
        if (it == tails.end()) {
            tails.push_back(h);
        } else {
            *it = h;
        }
    }
    
    cout << tails.size() << endl;
    return 0;
}
