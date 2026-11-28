#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;
    // Alternating sum of digits rule for 11
    long long temp = N < 0 ? -N : N;
    int sum = 0;
    bool add = true;
    while (temp > 0) {
        if (add) sum += temp % 10;
        else sum -= temp % 10;
        temp /= 10;
        add = !add;
    }
    cout << (sum % 11 == 0 ? "true" : "false") << endl;
    return 0;
}
