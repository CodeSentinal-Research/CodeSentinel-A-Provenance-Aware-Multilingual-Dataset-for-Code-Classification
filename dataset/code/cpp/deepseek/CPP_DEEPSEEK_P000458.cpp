Here's a simple C++ solution using Kadane's algorithm. Kadane's algorithm is a dynamic programming algorithm for solving the maximum subarray problem.

#include <iostream>
#include <climits>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int arr[N];
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int curr_sum = 0, max_sum = INT_MIN;
    for(int i = 0; i < N; i++) {
        curr_sum += arr[i];
        if(curr_sum > max_sum) {
            max_sum = curr_sum;
        }
        if(curr_sum < 0) {
            curr_sum = 0;
        }
    }

    cout << max_sum;
    return 0;
}

This program reads the size of the array (N) and the number of non-empty subarrays (M) from standard input. It then reads the array itself.

The program then uses Kadane's algorithm to find the maximum sum of any subarray in the array. It initializes two variables, curr_sum and max_sum, to 0 and the minimum possible integer, respectively. The program then iterates over the array, adding each element to curr_sum and updating max_sum if curr_sum is greater than max_sum. If curr_sum becomes less than 0, it resets it to 0.

Finally, the program outputs the maximum sum, which is stored in max_sum.