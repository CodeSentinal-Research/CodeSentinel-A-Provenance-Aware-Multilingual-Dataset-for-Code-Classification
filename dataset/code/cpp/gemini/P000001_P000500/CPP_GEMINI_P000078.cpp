#include <iostream>
int main() {
    int d;
    if (std::cin >> d) {
        int y = d / 365;
        int rem = d % 365;
        int w = rem / 7;
        int days = rem % 7;
        std::cout << y << " Years " << w << " Weeks " << days << " Days" << std::endl;
    }
    return 0;
}