#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> meetings(n);
    
    for(int i = 0; i < n; i++) {
        cin >> meetings[i].first >> meetings[i].second;
    }
    
    sort(meetings.begin(), meetings.end());
    
    int end = -1;
    int minRooms = 0;
    
    for(int i = 0; i < n; i++) {
        if(meetings[i].first <= end) {
            minRooms++;
        } else {
            end = meetings[i].second;
            minRooms++;
        }
    }
    
    cout << minRooms;
    
    return 0;
}