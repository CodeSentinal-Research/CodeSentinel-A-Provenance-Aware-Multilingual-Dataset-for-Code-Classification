#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, additionalRocks;
    cin >> n >> additionalRocks;
    vector<int> capacity(n), rocks(n);
    for (int i = 0; i < n; ++i) cin >> capacity[i];
    for (int i = 0; i < n; ++i) cin >> rocks[i];
    
    vector<int> needed(n);
    for (int i = 0; i < n; ++i) {
        needed[i] = capacity[i] - rocks[i];
    }
    
    sort(needed.begin(), needed.end());
    
    int fullBags = 0;
    for (int need : needed) {
        if (additionalRocks >= need) {
            additionalRocks -= need;
            fullBags++;
        } else {
            break;
        }
    }
    
    cout << fullBags << endl;
    return 0;
}
