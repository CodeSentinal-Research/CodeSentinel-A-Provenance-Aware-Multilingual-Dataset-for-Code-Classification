#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    long long windowSum = 0;
    for (int i = 0; i < k; ++i) windowSum += nums[i];
    
    cout << fixed << setprecision(1) << (double)windowSum / k;
    
    for (int i = k; i < n; ++i) {
        windowSum += nums[i] - nums[i-k];
        cout << " " << fixed << setprecision(1) << (double)windowSum / k;
    }
    cout << endl;
    
    return 0;
}
