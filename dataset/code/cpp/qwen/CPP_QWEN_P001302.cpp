#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> events(n);
    for (int i = 0; i < n; ++i) {
        cin >> events[i].first >> events[i].second;
    }
    
    vector<int> starts, ends;
    for (auto& e : events) {
        starts.push_back(e.first);
        ends.push_back(e.second);
    }
    
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());
    
    int rooms = 0;
    int maxRooms = 0;
    int i = 0, j = 0;
    
    while (i < n && j < n) {
        if (starts[i] < ends[j]) {
            rooms++;
            i++;
        } else {
            rooms--;
            j++;
        }
        maxRooms = max(maxRooms, rooms);
    }
    
    cout << maxRooms << endl;
    return 0;
}
