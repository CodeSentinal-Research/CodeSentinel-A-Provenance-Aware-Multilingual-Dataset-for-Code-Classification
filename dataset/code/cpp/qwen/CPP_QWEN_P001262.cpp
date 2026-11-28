#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> courses(n);
    for (int i = 0; i < n; ++i) {
        cin >> courses[i].first >> courses[i].second;
    }
    
    sort(courses.begin(), courses.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        return a.second < b.second;
    });
    
    priority_queue<int> maxHeap;
    int totalTime = 0;
    
    for (auto& c : courses) {
        totalTime += c.first;
        maxHeap.push(c.first);
        
        if (totalTime > c.second) {
            totalTime -= maxHeap.top();
            maxHeap.pop();
        }
    }
    
    cout << maxHeap.size() << endl;
    return 0;
}
