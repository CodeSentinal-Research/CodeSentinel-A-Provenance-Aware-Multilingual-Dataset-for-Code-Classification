#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> people(n);
    for (int i = 0; i < n; ++i) {
        cin >> people[i].first >> people[i].second;
    }
    
    // Sort by height descending, then by count ascending
    sort(people.begin(), people.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });
    
    vector<pair<int, int>> result;
    for (auto& p : people) {
        result.insert(result.begin() + p.second, p);
    }
    
    for (auto& p : result) {
        cout << p.first << " " << p.second << endl;
    }
    
    return 0;
}
