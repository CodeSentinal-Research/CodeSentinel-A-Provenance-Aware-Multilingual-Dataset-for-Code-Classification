#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long prod = 1;
    if (n == 0) prod = 0;
    while (n > 0) {
        prod *= n % 10;
        n /= 10;
    }
    cout << prod << endl;
    return 0;
}
