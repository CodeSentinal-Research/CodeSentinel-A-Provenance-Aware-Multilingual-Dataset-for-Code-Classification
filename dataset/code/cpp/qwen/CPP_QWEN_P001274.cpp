#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, coins;
    cin >> n >> coins;
    vector<int> costs(n);
    for (int i = 0; i < n; ++i) cin >> costs[i];
    
    sort(costs.begin(), costs.end());
    
    int count = 0;
    for (int c : costs) {
        if (coins >= c) {
            coins -= c;
            count++;
        } else {
            break;
        }
    }
    
    cout << count << endl;
    return 0;
}
