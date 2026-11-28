#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int leftSum = 0, rightSum = 0;
    for (int i = 0; i < n; ++i) {
        rightSum += nums[i];
    }

    for (int i = 0; i < n; ++i) {
        rightSum -= nums[i];
        if (leftSum == rightSum) {
            cout << i << endl;
            return 0;
        }
        leftSum += nums[i];
    }

    cout << -1 << endl;
    return 0;
}