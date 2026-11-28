#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> arr(N), brr(N);
    for (long long &i : arr) cin >> i;
    for (long long &i : brr) cin >> i;
    vector<long long> prefix_sum_arr(N + 1), prefix_sum_brr(N + 1);
    for (long long i = 0; i < N; i++) {
        prefix_sum_arr[i + 1] = prefix_sum_arr[i] + arr[i];
        prefix_sum_brr[i + 1] = prefix_sum_brr[i] + brr[i];
    }
    long long operations = 0;
    for (long long i = 0; i < N; i++) {
        operations += max(0LL, prefix_sum_arr[i + 1] - prefix_sum_brr[i + 1]);
    }
    cout << operations << endl;
    return 0;
}
This code reads the input, calculates the prefix sums, and then checks for the minimum number of operations to make all prefix sums of both arrays equal. It does this by iterating over the arrays and adding the difference between the prefix sum of the first array and the prefix sum of the second array at each index. The `max` function is used to ensure that the difference is never negative, and this difference is the number of operations required to make the prefix sums equal.