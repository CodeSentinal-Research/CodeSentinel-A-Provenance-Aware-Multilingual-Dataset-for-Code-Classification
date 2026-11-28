#include <iostream>
using namespace std;

int main() {
    long long A, B, M;
    cin >> A >> B >> M;

    long long result = (A + B) % M;

    cout << result << endl;

    return 0;
}