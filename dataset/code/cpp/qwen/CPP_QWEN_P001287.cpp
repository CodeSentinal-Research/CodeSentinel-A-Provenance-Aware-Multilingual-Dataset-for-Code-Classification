#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> sweetness(n);
    for (int i = 0; i < n; ++i) cin >> sweetness[i];
    
    long long low = *min_element(sweetness.begin(), sweetness.end());
    long long high = accumulate(sweetness.begin(), sweetness.end(), 0LL);
    
    auto canSplit = [&](long long minSweet) -> bool {
        int pieces = 0;
        long long currentSum = 0;
        for (int s : sweetness) {
            currentSum += s;
            if (currentSum >= minSweet) {
                pieces++;
                currentSum = 0;
            }
        }
        return pieces >= k + 1;
    };
    
    long long ans = 0;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (canSplit(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    cout << ans << endl;
    return 0;
}
