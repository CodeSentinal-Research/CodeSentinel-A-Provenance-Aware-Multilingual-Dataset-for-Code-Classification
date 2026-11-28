#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxProfit(int* prices, int pricesSize, int fee) {
    if (pricesSize == 0) return 0;
    int cash = 0, hold = -prices[0];
    for (int i = 1; i < pricesSize; i++) {
        cash = MAX(cash, hold + prices[i] - fee);
        hold = MAX(hold, cash - prices[i]);
    }
    return cash;
}