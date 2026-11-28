#include <iostream>
#include <utility>

int main() {
    // Optimize standard I/O operations for performance
    std::ios_base::sync_with_stdio(false);
    // Optimize standard I/O operations for performance
    std::cin.tie(nullptr);

    long long a{}, b{};
    if (std::cin >> a >> b) {
        std::swap(a, b);
        std::cout << a << " " << b << "\n";
    }

    return 0;
}