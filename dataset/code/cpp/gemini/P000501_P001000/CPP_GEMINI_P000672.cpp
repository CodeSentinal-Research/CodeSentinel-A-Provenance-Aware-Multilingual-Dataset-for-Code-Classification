#include <iostream>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> vals(n);
        for (int i = 0; i < n; i++) std::cin >> vals[i];
        int N; std::cin >> N;
        bool first = true;
        for (int i = 0; i < n; i++) {
            if ((i + 1) % N != 0) {
                if (!first) std::cout << " ";
                std::cout << vals[i];
                first = false;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}