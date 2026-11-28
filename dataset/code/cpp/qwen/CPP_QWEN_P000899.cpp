#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;
    // Sum of digits rule
    long long temp = N < 0 ? -N : N;
    long long sum = 0;
    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }
    cout << (sum % 3 == 0 ? "true" : "false") << endl;
    return 0;
}
