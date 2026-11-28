#include <limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxProfit(int* prices, int pricesSize) {
    int buy1 = INT_MAX, buy2 = INT_MAX;
    int profit1 = 0, profit2 = 0;

    for (int i = 0; i < pricesSize; i++) {
        int p = prices[i];
        buy1 = MIN(buy1, p);
        profit1 = MAX(profit1, p - buy1);
        buy2 = MIN(buy2, p - profit1);
        profit2 = MAX(profit2, p - buy2);
    }
    return profit2;
}