#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    long long windowProd = 1;
    for (int i = 0; i < k; ++i) windowProd *= nums[i];
    
    long long maxProd = windowProd;
    for (int i = k; i < n; ++i) {
        windowProd = windowProd / nums[i-k] * nums[i];
        maxProd = max(maxProd, windowProd);
    }
    
    cout << maxProd << endl;
    return 0;
}
