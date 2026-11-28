#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> names(n);
    vector<int> prices(n);
    for (int i = 0; i < n; i++) cin >> names[i] >> prices[i];
    int min_p, max_p;
    cin >> min_p >> max_p;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (prices[i] >= min_p && prices[i] <= max_p) { cout << names[i] << " " << prices[i] << endl; found = true; }
    }
    if (!found) cout << "No Products Found" << endl;
    return 0;
}
