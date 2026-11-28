Here is the C++ solution:

#include <iostream>
using namespace std;

int maxProfit(int prices[], int n) {
    int maxProfit = 0;
    int minPrice = prices[0];

    for(int i = 1; i < n; i++) {
        if(prices[i] < minPrice) {
            minPrice = prices[i];
        } else if(prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
        }
    }

    return maxProfit;
}

int main() {
    int n;
    cin >> n;

    int prices[n];

    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    cout << maxProfit(prices, n);

    return 0;
}
This program will take the number of stocks as input, and the prices of those stocks as input. It will then return the maximum profit that can be made from buying one stock and selling one after the given prices.