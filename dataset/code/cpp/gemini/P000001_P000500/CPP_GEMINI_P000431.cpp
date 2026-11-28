#include <iostream>
int main() {
    int n, target;
    if (std::cin >> n >> target) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            int v;
            std::cin >> v;
            if (v == target) count++;
        }
        std::cout << count << std::endl;
    }
    return 0;
}