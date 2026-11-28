#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    double maxAverage = numeric_limits<double>::lowest();
    for (int i = 0; i <= N - K; i++) {
        double sum = accumulate(nums.begin() + i, nums.begin() + i + K, 0.0);
        maxAverage = max(maxAverage, sum / K);
    }
    cout << maxAverage;
    return 0;
}