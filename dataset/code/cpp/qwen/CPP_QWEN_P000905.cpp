#include <iostream>
using namespace std;

int main() {
    long long A, B, M;
    cin >> A >> B >> M;
    long long res = ((A % M) - (B % M) + M) % M;
    cout << res << endl;
    return 0;
}
