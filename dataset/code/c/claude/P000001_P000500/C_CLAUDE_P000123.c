#include <limits.h>
int maxProfit(int* prices, int n) {
    int minPrice = INT_MAX, maxProfit = 0;
    for (int i = 0; i < n; i++) {
        if (prices[i] < minPrice) minPrice = prices[i];
        int profit = prices[i] - minPrice;
        if (profit > maxProfit) maxProfit = profit;
    }
    return maxProfit;
}
