#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int min_price = INT_MAX, max_profit = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x < min_price) {
            min_price = x;
        } else if (x - min_price > max_profit) {
            max_profit = x - min_price;
        }
    }
    cout << max_profit << "\n";
    return 0;
}
