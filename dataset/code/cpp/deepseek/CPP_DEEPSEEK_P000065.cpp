#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int a, b, c;
    cout << "Enter three positive integers: ";
    cin >> a >> b >> c;
    if (a <= 0 || b <= 0 || c <= 0 || a > 100 || b > 100 || c > 100) {
        cout << "Inputs should be between 1 and 100.";
        return 0;
    }
    int result = lcm(a, lcm(b, c));
    cout << "LCM of " << a << ", " << b << ", and " << c << " is: " << result;
    return 0;
}