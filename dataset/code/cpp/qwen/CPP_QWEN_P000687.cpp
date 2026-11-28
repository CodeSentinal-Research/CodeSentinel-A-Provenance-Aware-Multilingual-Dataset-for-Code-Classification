#include <iostream>
using namespace std;
int sumDigits(long long n) {
    if(n == 0) return 0;
    return (n % 10) + sumDigits(n / 10);
}
int main() {
    long long n; cin >> n;
    cout << sumDigits(n) << endl;
    return 0;
}
