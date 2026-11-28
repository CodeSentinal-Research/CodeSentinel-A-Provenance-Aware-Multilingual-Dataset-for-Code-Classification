#include <iostream>
void print_n_to_1(int n) {
    if (n <= 0) return;
    std::cout << n << " ";
    print_n_to_1(n - 1);
}
int main() {
    int n;
    if (std::cin >> n) {
        print_n_to_1(n);
        std::cout << std::endl;
    }
    return 0;
}