#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    int maxVal = *max_element(nums.begin(), nums.begin() + k);
    cout << maxVal << endl;
    
    return 0;
}
