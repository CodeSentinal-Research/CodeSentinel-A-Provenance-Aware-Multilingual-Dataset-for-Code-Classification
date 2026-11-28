#include <iostream>
#include <limits>

int main() {
    int num1, num2;

    std::cout << "Enter the first integer: ";
    while (!(std::cin >> num1)) {
        std::cout << "Invalid input. Please enter an integer: ";
        std::cin.clear(); // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
    }

    std::cout << "Enter the second integer: ";
    while (!(std::cin >> num2)) {
        std::cout << "Invalid input. Please enter an integer: ";
        std::cin.clear(); // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
    }

    int result = num1 - num2;
    std::cout << "Result of subtraction: " << result << std::endl;

    return 0;
}