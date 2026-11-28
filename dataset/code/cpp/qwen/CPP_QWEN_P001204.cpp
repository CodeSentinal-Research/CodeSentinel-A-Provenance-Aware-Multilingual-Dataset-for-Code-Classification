#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    if (n <= 1) {
        cout << n << endl;
        return 0;
    }
    
    int up = 1, down = 1;
    for (int i = 1; i < n; ++i) {
        if (nums[i] > nums[i-1]) {
            up = down + 1;
        } else if (nums[i] < nums[i-1]) {
            down = up + 1;
        }
    }
    
    cout << max(up, down) << endl;
    return 0;
}
