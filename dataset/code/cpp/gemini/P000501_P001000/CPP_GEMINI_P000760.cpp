#include <iostream>
#include <string>
void inc_numbers(int n, int start, std::string cur) {
    if ((int)cur.length() == n) {
        std::cout << cur << std::endl;
        return;
    }
    for (int d = start; d <= 9; d++) {
        inc_numbers(n, d + 1, cur + std::to_string(d));
    }
}
int main() {
    int n;
    if (std::cin >> n) {
        if (n == 1) std::cout << 0 << std::endl;
        inc_numbers(n, 1, "");
    }
    return 0;
}