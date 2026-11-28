#include <iostream>
using namespace std;

int main() {
    long long A, B;
    cin >> A >> B;
    while (B != 0) {
        long long T = B;
        B = A % B;
        A = T;
    }
    cout << A;
    return 0;
}