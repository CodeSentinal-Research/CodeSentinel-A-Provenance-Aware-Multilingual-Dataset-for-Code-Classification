#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, truckSize;
    cin >> n >> truckSize;
    vector<pair<int, int>> boxTypes(n); // {unitsPerBox, numberOfBoxes}
    for (int i = 0; i < n; ++i) {
        cin >> boxTypes[i].second >> boxTypes[i].first;
    }
    
    sort(boxTypes.rbegin(), boxTypes.rend());
    
    int totalUnits = 0;
    for (auto& bt : boxTypes) {
        if (truckSize == 0) break;
        int take = min(truckSize, bt.second);
        totalUnits += take * bt.first;
        truckSize -= take;
    }
    
    cout << totalUnits << endl;
    return 0;
}
