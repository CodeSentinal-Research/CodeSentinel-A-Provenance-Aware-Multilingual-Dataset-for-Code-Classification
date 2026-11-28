#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> plantTime(n), growTime(n);
    for (int i = 0; i < n; ++i) cin >> plantTime[i];
    for (int i = 0; i < n; ++i) cin >> growTime[i];
    
    vector<pair<int, int>> flowers(n);
    for (int i = 0; i < n; ++i) {
        flowers[i] = {growTime[i], plantTime[i]};
    }
    
    sort(flowers.rbegin(), flowers.rend());
    
    long long currentTime = 0;
    long long maxBloomTime = 0;
    
    for (auto& f : flowers) {
        currentTime += f.second;
        maxBloomTime = max(maxBloomTime, currentTime + f.first);
    }
    
    cout << maxBloomTime << endl;
    return 0;
}
