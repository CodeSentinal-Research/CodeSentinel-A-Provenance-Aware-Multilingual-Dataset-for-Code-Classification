#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; ++i) {
        cin >> tasks[i].first >> tasks[i].second;
    }
    
    // Sort by minimum energy required descending
    sort(tasks.begin(), tasks.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        return a.second > b.second;
    });
    
    long long minEnergy = 0;
    long long currEnergy = 0;
    
    for (auto& t : tasks) {
        if (currEnergy < t.second) {
            minEnergy += t.second - currEnergy;
            currEnergy = t.second;
        }
        currEnergy -= t.first;
    }
    
    cout << minEnergy << endl;
    return 0;
}
