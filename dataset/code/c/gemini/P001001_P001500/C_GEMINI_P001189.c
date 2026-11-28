#include <limits.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxProfit(int k, int* prices, int pricesSize) {
    if (pricesSize == 0 || k == 0) return 0;
    if (k >= pricesSize / 2) {
        int res = 0;
        for (int i = 1; i < pricesSize; i++) {
            if (prices[i] > prices[i - 1]) res += prices[i] - prices[i - 1];
        }
        return res;
    }

    int* buy = (int*)malloc((k + 1) * sizeof(int));
    int* profit = (int*)calloc(k + 1, sizeof(int));
    for (int i = 0; i <= k; i++) buy[i] = INT_MAX;

    for (int j = 0; j < pricesSize; j++) {
        int p = prices[j];
        for (int i = 1; i <= k; i++) {
            buy[i] = MIN(buy[i], p - profit[i - 1]);
            profit[i] = MAX(profit[i], p - buy[i]);
        }
    }
    int ans = profit[k];
    free(buy);
    free(profit);
    return ans;
}