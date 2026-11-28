#include <iostream>
#include <stdexcept>

int divide(int numerator, int denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("Division by zero is not allowed.");
    }
    return numerator / denominator;
}

int main() {
    int num1, num2;
    
    std::cout << "Enter two integers (numerator and denominator): ";
    std::cin >> num1 >> num2;

    try {
        int result = divide(num1, num2);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}