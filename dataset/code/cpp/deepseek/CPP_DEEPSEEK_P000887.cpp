Here is a C++ code snippet that solves the problem:

#include <iostream>
using namespace std;

bool isNeon(int N) {
    if (N < 0 || N > 1000000000) {
        return false;
    }
    int sum = 0;
    int num = N;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum == N;
}

int main() {
    int N;
    cin >> N;
    if (isNeon(N)) {
        cout << "true";
    } else {
        cout << "false";
    }
    return 0;
}

This code first checks if the input number is within the given constraints. If not, it returns false. If it is, it calculates the sum of all digits in the number by repeatedly dividing the number by 10 and adding the remainder to the sum. If the sum is equal to the original number, it returns true, otherwise false.