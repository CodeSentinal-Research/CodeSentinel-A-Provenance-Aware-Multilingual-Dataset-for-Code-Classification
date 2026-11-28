#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    long long num, den;
    cin >> num >> den;
    long long g = gcd(num, den);
    cout << num / g << " " << den / g << endl;
    return 0;
}
