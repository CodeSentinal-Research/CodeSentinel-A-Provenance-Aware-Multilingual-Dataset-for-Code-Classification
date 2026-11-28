#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxProfit(int* prices, int pricesSize) {
    int sold = 0, held = -1000000000, reset = 0;
    for (int i = 0; i < pricesSize; i++) {
        int p = prices[i];
        int preSold = sold;
        sold = held + p;
        held = MAX(held, reset - p);
        reset = MAX(reset, preSold);
    }
    return MAX(sold, reset);
}