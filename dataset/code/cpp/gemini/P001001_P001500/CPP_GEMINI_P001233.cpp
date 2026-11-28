#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Item {
    int val, wt;
};

int main() {
    int n, w;
    if (std::cin >> n >> w) {
        std::vector<Item> items(n);
        for (int i = 0; i < n; i++) std::cin >> items[i].val >> items[i].wt;

        std::sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
            return (double)a.val / a.wt > (double)b.val / b.wt;
        });

        double totalVal = 0.0;
        int cap = w;

        for (const auto& it : items) {
            if (cap >= it.wt) {
                totalVal += it.val;
                cap -= it.wt;
            } else {
                totalVal += (double)it.val * ((double)cap / it.wt);
                break;
            }
        }
        std::cout << std::fixed << std::setprecision(6) << totalVal << "\n";
    }
    return 0;
}