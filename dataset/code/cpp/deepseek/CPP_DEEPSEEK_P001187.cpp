Here is the C++ code for the problem:

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int maxProfit = 0;
    for(int i = 0; i < n - 1; i++) {
        if (prices[i+1] > prices[i])
            maxProfit += prices[i+1] - prices[i];
    }
    return maxProfit;
}

int main() {
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    int maxProfit = maxProfit(prices);
    cout << maxProfit << endl;
    return 0;
}
In this code, we are iterating through the prices array and adding the profit to the maxProfit whenever we find a profit that is greater than the current price. The profit is calculated by subtracting the current price from the next price.