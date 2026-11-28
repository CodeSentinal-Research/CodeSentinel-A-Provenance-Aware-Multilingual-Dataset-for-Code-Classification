Here is the C++ code to solve the problem:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n < 2) return 0;

    vector<int> left(n, 0), right(n, 0), maxLeft(n, 0), minRight(n, 0);
    int minPrice = prices[0];
    for (int i = 1; i < n; ++i) {
        minPrice = min(minPrice, prices[i]);
        left[i] = max(left[i - 1], prices[i] - minPrice);
    }

    int maxPrice = prices[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        maxPrice = max(maxPrice, prices[i]);
        right[i] = max(right[i + 1], maxPrice - prices[i]);
   
    }

    int profit = 0;
    for (int i = 0; i < n; ++i) {
        profit = max(profit, left[i] + right[i]);
    }

    return profit;
}

int main() {
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }
    cout << maxProfit(prices) << endl;
    return 0;
}

This code first calculates the maximum profit we can obtain by selling at the most one time on the left side of the array. Then it calculates the maximum profit we can obtain by selling at most two times on the right side of the array. Finally, it returns the maximum of the two possible maximum profit values.