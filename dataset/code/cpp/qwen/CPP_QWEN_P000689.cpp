#include <iostream>
using namespace std;
long long prodDigits(long long n) {
    if(n == 0) return 1;
    return (n % 10) * prodDigits(n / 10);
}
int main() {
    long long n; cin >> n;
    cout << prodDigits(n) << endl;
    return 0;
}
