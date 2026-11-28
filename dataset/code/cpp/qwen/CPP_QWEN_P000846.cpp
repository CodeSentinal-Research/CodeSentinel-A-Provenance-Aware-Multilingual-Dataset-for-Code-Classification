#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool canDistributeProducts(const vector<int>& quantities, int n, int maxPerStore) {
    long long storesNeeded = 0;
    for (int q : quantities) {
        storesNeeded += (q + maxPerStore - 1) / maxPerStore;
    }
    return storesNeeded <= n;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> quantities(m);
    for (int i = 0; i < m; ++i) cin >> quantities[i];
    
    int low = 1;
    int high = *max_element(quantities.begin(), quantities.end());
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (canDistributeProducts(quantities, n, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low << endl;
    return 0;
}
