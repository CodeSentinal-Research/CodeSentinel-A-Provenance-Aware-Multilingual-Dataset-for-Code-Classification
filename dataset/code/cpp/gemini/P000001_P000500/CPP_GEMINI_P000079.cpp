#include <iostream>
int main() {
    int s;
    if (std::cin >> s) {
        int h = s / 3600;
        int rem = s % 3600;
        int m = rem / 60;
        int sec = rem % 60;
        std::cout << h << " Hours " << m << " Minutes " << sec << " Seconds" << std::endl;
    }
    return 0;
}