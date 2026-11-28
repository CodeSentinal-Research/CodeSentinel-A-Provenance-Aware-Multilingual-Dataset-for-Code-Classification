#include <iostream>
#include <vector>
int main() {
    int size;
    if (std::cin >> size) {
        std::vector<int> vals(size);
        for (int i = 0; i < size; i++) std::cin >> vals[i];
        int n; std::cin >> n;
        if (n >= 1 && n <= size) std::cout << vals[n - 1] << std::endl;
        else std::cout << -1 << std::endl;
    }
    return 0;
}