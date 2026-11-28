#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    long long count = 0;
    long long product = 1;
    int left = 0;
    
    for (int right = 0; right < n; ++right) {
        product *= nums[right];
        while (left <= right && product >= k) {
            product /= nums[left];
            left++;
        }
        count += (right - left + 1);
    }
    
    cout << count << endl;
    return 0;
}
