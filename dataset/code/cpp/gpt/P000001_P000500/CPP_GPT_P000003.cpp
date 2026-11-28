#include <iostream>
#include <limits>

int main() {
    int num1, num2;

    std::cout << "Enter two integers: ";
    
    // Input validation for the first integer
    while (!(std::cin >> num1)) {
        std::cout << "Invalid input. Please enter an integer: ";
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    }

    // Input validation for the second integer
    while (!(std::cin >> num2)) {
        std::cout << "Invalid input. Please enter an integer: ";
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    }

    long long product = static_cast<long long>(num1) * static_cast<long long>(num2);
    std::cout << "The product of " << num1 << " and " << num2 << " is " << product << std::endl;

    return 0;
}