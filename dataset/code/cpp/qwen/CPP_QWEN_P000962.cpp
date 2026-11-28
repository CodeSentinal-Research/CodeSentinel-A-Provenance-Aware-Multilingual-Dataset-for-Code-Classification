#include <iostream>
using namespace std;

int main() {
    long long A, B;
    cin >> A >> B;
    // Frobenius number for two coprime integers A, B is AB - A - B
    cout << A * B - A - B << endl;
    return 0;
}
