#include <iostream>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> vals(n);
        for (int i = 0; i < n; i++) std::cin >> vals[i];
        int x; std::cin >> x;
        std::vector<int> less, greater;
        for (int v : vals) {
            if (v < x) less.push_back(v);
            else greater.push_back(v);
        }
        for (size_t i = 0; i < less.size(); i++) std::cout << less[i] << " ";
        for (size_t i = 0; i < greater.size(); i++) {
            std::cout << greater[i] << (i + 1 == greater.size() ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}