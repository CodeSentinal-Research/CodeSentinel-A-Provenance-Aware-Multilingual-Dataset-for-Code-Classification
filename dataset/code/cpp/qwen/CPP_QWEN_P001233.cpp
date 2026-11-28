#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    vector<pair<double, pair<int, int>>> items(n); // ratio, {value, weight}
    
    for (int i = 0; i < n; ++i) {
        int wt, val;
        cin >> wt >> val;
        items[i] = {(double)val / wt, {val, wt}};
    }
    
    sort(items.rbegin(), items.rend());
    
    double totalValue = 0.0;
    int remainingCapacity = w;
    
    for (int i = 0; i < n; ++i) {
        if (remainingCapacity == 0) break;
        int wt = items[i].second.second;
        int val = items[i].second.first;
        
        if (wt <= remainingCapacity) {
            totalValue += val;
            remainingCapacity -= wt;
        } else {
            totalValue += (double)val * remainingCapacity / wt;
            remainingCapacity = 0;
        }
    }
    
    cout << fixed << setprecision(2) << totalValue << endl;
    return 0;
}
