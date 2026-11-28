#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        res ^= nums[i];
    }
    cout << res << endl;
    return 0;
}
