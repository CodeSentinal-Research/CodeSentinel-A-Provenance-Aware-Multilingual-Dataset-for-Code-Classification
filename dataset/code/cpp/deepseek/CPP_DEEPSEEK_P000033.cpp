#include <iostream>

int main() {
    int N;
    std::cout << "Enter a positive integer N: ";
    std::cin >> N;

    int sum = 0;
    for(int i = 1; i <= N; i++) {
        if(i % 2 == 0) {
            sum += i;
        }
    }

    std::cout << "The sum of even numbers up to " << N << " is: " << sum << std::endl;

    return 0;
}