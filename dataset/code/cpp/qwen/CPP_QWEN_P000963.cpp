#include <iostream>
using namespace std;

int main() {
    long long A, B, N;
    cin >> A >> B >> N;
    // Check if N can be formed by Ax + By
    // Brute force for small A, B? Or check modulo.
    // If gcd(A,B) does not divide N, impossible.
    // Since A, B coprime in Frobenius context, always possible for large N.
    // For specific N, check.
    
    bool possible = false;
    for (long long x = 0; x * A <= N; ++x) {
        if ((N - x * A) % B == 0) {
            possible = true;
            break;
        }
    }
    cout << (possible ? "true" : "false") << endl;
    return 0;
}
