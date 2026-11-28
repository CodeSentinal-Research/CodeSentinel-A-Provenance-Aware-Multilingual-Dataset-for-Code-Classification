#include <iostream>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> even, odd;
        for (int i = 0; i < n; i++) {
            int x; std::cin >> x;
            if (x % 2 == 0) even.push_back(x);
            else odd.push_back(x);
        }
        for (size_t i = 0; i < even.size(); i++) std::cout << even[i] << " ";
        for (size_t i = 0; i < odd.size(); i++) {
            std::cout << odd[i] << (i + 1 == odd.size() ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}