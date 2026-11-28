#include <iostream>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> vals(n);
        for (int i = 0; i < n; i++) std::cin >> vals[i];
        int pos, val; std::cin >> pos >> val;
        vals.insert(vals.begin() + pos, val);
        for (size_t i = 0; i < vals.size(); i++) {
            std::cout << vals[i] << (i + 1 == vals.size() ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}