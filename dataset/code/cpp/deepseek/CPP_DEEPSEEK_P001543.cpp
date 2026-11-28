Here is the C++ code for the problem:

#include <iostream>
#include <deque>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    deque<int> nums;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    int minSum = INT_MAX, sum = 0;
    for (int i = 0; i < K; i++) {
        sum += nums[i];
    }
    minSum = sum;

    for (int i = K; i < N; i++) {
        sum = sum - nums[i - K] + nums[i];
        minSum = min(minSum, sum);
    }

    cout << minSum << endl;

    return 0;
}
This program first reads the number of elements N and the size K. Then it reads N integers. After that, it calculates the sum of the first K elements. It also keeps track of the minimum sum found so far. For each subsequent element in the deque, it subtracts the element going out and adds the element coming in, this way it updates the sum. If the current sum is smaller than the minimum sum, it updates the minimum sum. Finally, it prints the minimum sum.