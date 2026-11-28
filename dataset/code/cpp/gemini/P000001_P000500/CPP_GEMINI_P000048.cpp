#include <iostream>
int main() {
    double scored, total;
    if (std::cin >> scored >> total) {
        std::cout << (scored / total) * 100.0 << std::endl;
    }
    return 0;
}