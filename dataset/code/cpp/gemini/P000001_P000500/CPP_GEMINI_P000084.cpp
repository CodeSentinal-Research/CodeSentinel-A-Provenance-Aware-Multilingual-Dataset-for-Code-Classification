#include <iostream>
int main() {
    int age;
    if (std::cin >> age) std::cout << (age >= 18 ? "Eligible" : "Not Eligible") << std::endl;
    return 0;
}