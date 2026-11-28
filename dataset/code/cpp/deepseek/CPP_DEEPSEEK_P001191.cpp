Here is the code:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    int buy = -prices[0], sell = 0;
    for(int i = 1; i < n; i++){
        buy = max(buy, sell - prices[i]);
        sell = max(sell, buy + prices[i] - fee);
    }
    return sell;
}

int main(){
    int N, Fee;
    cin >> N >> Fee;
    vector<int> prices(N);
    for(int &i : prices) cin >> i;
    cout << maxProfit(prices, Fee) << endl;
    return 0;
}

This code first takes the number of days and transaction fee as input, then takes the price of each day as input. After that, it calls the `maxProfit` function with the prices and fee as arguments and prints the result.