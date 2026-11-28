#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;
    long long temp = N;
    long long sum = 0;
    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }
    cout << (N % sum == 0 ? "true" : "false") << endl;
    return 0;
}
