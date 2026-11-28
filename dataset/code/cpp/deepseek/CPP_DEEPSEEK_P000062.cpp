#include <iostream>
#include <math.h>

using namespace std;

int factorial(int n) {
    int fact = 1;
    for(int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

bool isStrongNumber(int n) {
    int sum = 0;
    while(n != 0) {
        sum += factorial(n % 10);
        n /= 10;
    }
    return sum == n;
}

int main() {
    int n;
    cin >> n;
    if(n >= 1 && n <= 100000) {
        if(isStrongNumber(n)) {
            cout << "Strong";
        } else {
            cout << "Not Strong";
        }
    } else {
        cout << "Invalid input";
    }
    return 0;
}