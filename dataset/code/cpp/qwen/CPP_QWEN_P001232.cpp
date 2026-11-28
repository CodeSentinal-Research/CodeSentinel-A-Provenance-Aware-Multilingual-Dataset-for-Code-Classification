#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> activities(n);
    for (int i = 0; i < n; ++i) {
        cin >> activities[i].first >> activities[i].second;
    }
    
    // Sort by finish time
    sort(activities.begin(), activities.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        return a.second < b.second;
    });
    
    int count = 1;
    int lastFinish = activities[0].second;
    
    for (int i = 1; i < n; ++i) {
        if (activities[i].first >= lastFinish) {
            count++;
            lastFinish = activities[i].second;
        }
    }
    
    cout << count << endl;
    return 0;
}
