#include <iostream>

int main()
{
    double fahrenheit;
    std::cout << "Enter temperature in Fahrenheit: ";
    std::cin >> fahrenheit;

    double celsius = (fahrenheit - 32) * 5.0 / 9.0;
    std::cout << "Temperature in Celsius: " << celsius << std::endl;

    return 0;
}