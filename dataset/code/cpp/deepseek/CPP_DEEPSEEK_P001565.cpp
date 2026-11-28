#include <iostream>
#include <deque>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    deque<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    while (K > 0) {
        int max_idx = 0;
        for (int i = 1; i < K; ++i) {
            if (nums[i] > nums[max_idx]) {
                max_idx = i;
            }
        }

        cout << nums[max_idx] << " ";

        nums.pop_front();
        --K;
    }

    cout << "\n";

    return 0;
}