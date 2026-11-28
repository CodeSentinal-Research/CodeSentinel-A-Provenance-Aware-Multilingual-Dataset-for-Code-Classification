#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int prices[n];
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    sort(prices, prices + n);

    int max_diff = prices[n - 1] - prices[0];
    for (int i = 0; i < n - k + 1; i++) {
        max_diff = min(max_diff, prices[i + k - 1] - prices[i]);
    }

    cout << max_diff;

    return 0;
}
This C++ code reads the number of candies (n) and the number to be chosen (k) and the prices of the candies from the standard input. It then sorts the prices in ascending order. The maximum difference between any two chosen candies is then found and printed to the standard output.