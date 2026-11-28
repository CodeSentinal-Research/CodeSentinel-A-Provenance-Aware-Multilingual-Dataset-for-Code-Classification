#include <iostream>
#include <cmath>
void hanoi(int n, char src, char dst, char aux) {
    if (n == 1) {
        std::cout << "Move disk 1 from " << src << " to " << dst << std::endl;
        return;
    }
    hanoi(n - 1, src, aux, dst);
    std::cout << "Move disk " << n << " from " << src << " to " << dst << std::endl;
    hanoi(n - 1, aux, dst, src);
}
int main() {
    int n;
    if (std::cin >> n) {
        hanoi(n, 'A', 'C', 'B');
        std::cout << (1LL << n) - 1 << std::endl;
    }
    return 0;
}