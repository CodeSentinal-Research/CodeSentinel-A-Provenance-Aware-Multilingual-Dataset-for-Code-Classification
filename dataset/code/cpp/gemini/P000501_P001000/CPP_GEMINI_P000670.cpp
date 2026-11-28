#include <iostream>
int main() {
    int n;
    if (std::cin >> n) {
        long long s = 0;
        for (int i = 0; i < n; i++) {
            int x; std::cin >> x; s += x;
        }
        std::cout << s << std::endl;
    }
    return 0;
}