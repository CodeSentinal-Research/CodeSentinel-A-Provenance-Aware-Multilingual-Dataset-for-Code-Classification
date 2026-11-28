#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int prefix_length = 0;
    int total = 0;
    while (true) {
        bool valid = true;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (i + prefix_length >= n) {
                valid = false;
                break;
            }
            sum += nums[i + prefix_length];
        }
        if (valid && sum >= x) {
            break;
        }
        prefix_length++;
    }

    if (prefix_length == 0) {
        cout << -1 << endl;
    } else {
        cout << prefix_length << endl;
    }

    return 0;
}