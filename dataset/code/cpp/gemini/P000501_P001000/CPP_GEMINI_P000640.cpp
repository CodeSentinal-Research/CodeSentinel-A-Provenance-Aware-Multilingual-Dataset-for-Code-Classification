#include <iostream>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> vals(n);
        for (int i = 0; i < n; i++) std::cin >> vals[i];
        int val; std::cin >> val;
        std::cout << val;
        for (int i = 0; i < n; i++) std::cout << " " << vals[i];
        std::cout << std::endl;
    }
    return 0;
}