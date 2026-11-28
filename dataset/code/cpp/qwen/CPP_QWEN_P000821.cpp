#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];

    int low = 0, high = n - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        // If mid is even, pair is (mid, mid+1)
        // If mid is odd, pair is (mid-1, mid)
        // We want to find the first element of the unpaired one.
        
        // Ensure mid is even for comparison logic
        if (mid % 2 == 1) mid--;
        
        if (nums[mid] == nums[mid + 1]) {
            low = mid + 2;
        } else {
            high = mid;
        }
    }
    cout << nums[low] << endl;
    return 0;
}
