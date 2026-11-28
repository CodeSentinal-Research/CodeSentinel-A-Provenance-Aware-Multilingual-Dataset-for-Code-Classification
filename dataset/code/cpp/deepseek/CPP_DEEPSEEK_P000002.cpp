#include <iostream>

int main()
{
    int a, b;
    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;
    std::cout << "The result of subtracting " << b << " from " << a << " is " << (a - b) << std::endl;
    return 0;
}