#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int target, startFuel, n;
    cin >> target >> startFuel >> n;
    
    vector<pair<int, int>> stations(n);
    for (int i = 0; i < n; ++i) {
        cin >> stations[i].first >> stations[i].second;
    }
    
    // Sort by position
    sort(stations.begin(), stations.end());
    
    priority_queue<int> maxHeap;
    int currFuel = startFuel;
    int stops = 0;
    int prevPos = 0;
    
    for (int i = 0; i < n; ++i) {
        int dist = stations[i].first - prevPos;
        while (currFuel < dist) {
            if (maxHeap.empty()) {
                cout << -1 << endl;
                return 0;
            }
            currFuel += maxHeap.top();
            maxHeap.pop();
            stops++;
        }
        currFuel -= dist;
        maxHeap.push(stations[i].second);
        prevPos = stations[i].first;
    }
    
    // Last leg to target
    int distToTarget = target - prevPos;
    while (currFuel < distToTarget) {
        if (maxHeap.empty()) {
            cout << -1 << endl;
            return 0;
        }
        currFuel += maxHeap.top();
        maxHeap.pop();
        stops++;
    }
    
    cout << stops << endl;
    return 0;
}
