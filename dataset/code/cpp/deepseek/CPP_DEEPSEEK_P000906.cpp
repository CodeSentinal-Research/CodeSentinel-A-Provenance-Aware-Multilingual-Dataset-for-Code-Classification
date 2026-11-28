#include <iostream>
using namespace std;

int main() {
    long long A, B, M;
    cin >> A >> B >> M;

    A = A % M;
    B = B % M;

    cout << (A * B) % M << endl;

    return 0;
}