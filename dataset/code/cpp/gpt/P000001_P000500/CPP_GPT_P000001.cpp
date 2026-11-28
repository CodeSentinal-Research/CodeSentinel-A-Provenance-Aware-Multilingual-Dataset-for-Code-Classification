#include <iostream>
#include <limits>

int main() {
    int num1, num2;

    std::cout << "Enter first integer: ";
    while (!(std::cin >> num1)) {
        std::cout << "Invalid input. Please enter an integer: ";
        std::cin.clear(); // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
    }

    std::cout << "Enter second integer: ";
    while (!(std::cin >> num2)) {
        std::cout << "Invalid input. Please enter an integer: ";
        std::cin.clear(); // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
    }

    int sum = num1 + num2;
    std::cout << "The sum of " << num1 << " and " << num2 << " is " << sum << "." << std::endl;

    return 0;
}