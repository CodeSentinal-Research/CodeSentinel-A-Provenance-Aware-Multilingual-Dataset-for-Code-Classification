#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> meetings(n);
    for (int i = 0; i < n; ++i) {
        cin >> meetings[i].first >> meetings[i].second;
    }
    
    // Sort by end time
    sort(meetings.begin(), meetings.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        return a.second < b.second;
    });
    
    int count = 1;
    int lastEnd = meetings[0].second;
    
    for (int i = 1; i < n; ++i) {
        if (meetings[i].first >= lastEnd) {
            count++;
            lastEnd = meetings[i].second;
        }
    }
    
    cout << count << endl;
    return 0;
}
