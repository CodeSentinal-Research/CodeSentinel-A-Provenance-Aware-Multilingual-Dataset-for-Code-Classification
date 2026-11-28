Here is the code:

#include <iostream>
using namespace std;

long long gcd(long long a, long long b){
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int main(){
    long long a, b;
    cout << "Enter two positive integers: ";
    cin >> a >> b;
    cout << "The Greatest Common Divisor is: " << gcd(a, b);
    return 0;
}

This program uses a recursive function to calculate the greatest common divisor (GCD) of two numbers. The function uses the Euclidean algorithm to find the GCD. The Euclidean algorithm is based on the principle that the greatest common divisor of two numbers does not change if the larger number is replaced by its difference with the smaller number. The algorithm reduces the problem of finding the GCD of two numbers to finding the GCD of the smaller two numbers. This is the key idea behind the recursive solution.