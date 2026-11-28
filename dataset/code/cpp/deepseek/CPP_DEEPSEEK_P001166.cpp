Here is the C++ code for the problem:

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int max_sum = -1e9;
    int max_ending_here = 0;
    int max_ending_prev = 0;
    for (int i = 0; i < n; i++) {
        max_ending_here = max(arr[i], max_ending_here + arr[i]);
        max_ending_prev = max(max_ending_prev + arr[i], max_ending_here);
        max_sum = max(max_sum, max_ending_prev);
    }
    cout << max_sum;
    return 0;
}
This code works by first reading the size of the array, then the array itself. It then initializes several variables to keep track of the maximum sum we've seen so far, the maximum sum ending at the current position (max_ending_here), and the maximum sum we've seen so far when we've advanced one position.

We iterate through the array and update max_ending_here and max_ending_prev in each iteration. If the current element plus the previous one is greater than the current element, then we update max_ending_here to be the current element plus the previous one. Otherwise, we update max_ending_here to be the current element.

Then we update max_sum to be the maximum of max_sum and max_ending_prev.

Finally, we print out the maximum sum.