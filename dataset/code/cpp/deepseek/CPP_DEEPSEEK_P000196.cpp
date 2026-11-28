#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int max_sum = 0;
    deque<int> window(K);
    for (int i = 0; i < N; i++) {
        if (i >= K) {
            max_sum = max(max_sum, window[0]);
            window.pop_front();
        }
        window.push_back(nums[i]);
    }

    cout << max_sum << endl;

    return 0;
}