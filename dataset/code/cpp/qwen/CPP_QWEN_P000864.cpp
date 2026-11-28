#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    int xorAll = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        xorAll ^= nums[i];
    }
    for (int i = 0; i <= n; ++i) {
        xorAll ^= i;
    }
    cout << xorAll << endl;
    return 0;
}
