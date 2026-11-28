#include <iostream>

int main() {
    int year;
    if (std::cin >> year) {
        bool is_leap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
        if (is_leap) {
            std::cout << "Leap Year" << std::endl;
        } else {
            std::cout << "Not a Leap Year" << std::endl;
        }
    }
    return 0;
}