#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    for (int mask = 0; mask < (1 << N); mask++) {
        vector<int> subset;
        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) {
                subset.push_back(nums[i]);
            }
        }

        sort(subset.begin(), subset.end());

        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}