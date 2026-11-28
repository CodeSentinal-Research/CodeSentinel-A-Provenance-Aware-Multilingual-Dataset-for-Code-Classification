#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> quantities(m);
    for (int i = 0; i < m; i++) {
        cin >> quantities[i];
    }

    sort(quantities.begin(), quantities.end());

    int maxProduct = -1;
    for (int i = m - 1; i >= 0; i -= n) {
        int product = quantities[i];
        for (int j = i - 1; j >= i - n && j >= 0; j--) {
            product *= quantities[j];
        }
        maxProduct = max(product, maxProduct);
    }

    cout << maxProduct;

    return 0;
}