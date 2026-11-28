#include <iostream>
using namespace std;

int main() {
    long long A, B, M;
    cin >> A >> B >> M;
    cout << ((A % M) + (B % M)) % M << endl;
    return 0;
}
