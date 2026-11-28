#include <iostream>
using namespace std;

int main() {
    long long s, n, m;
    cin >> s >> n >> m;
    
    // Total food needed
    long long totalNeeded = s * m;
    
    // Max food purchasable in one day
    long long maxPurchase = n;
    
    // If we can't buy enough for one day or Sunday is closed and we need more than 6 days worth?
    // Simplified: We can buy on any day except possibly Sundays? Problem doesn't specify Sundays.
    // Standard survival problem: Buy N per day. Need M per day.
    // If N < M, impossible unless we can store.
    // Assuming we can store unlimited food.
    
    if (n < m) {
        // Check if we can survive by buying extra on other days?
        // Usually this problem implies a weekly cycle with Sunday closed.
        // Without Sunday constraint, if N >= M, answer is ceil(S*M / N).
        // If N < M, impossible.
        cout << -1 << endl;
    } else {
        long long days = (totalNeeded + n - 1) / n;
        cout << days << endl;
    }
    
    return 0;
}
