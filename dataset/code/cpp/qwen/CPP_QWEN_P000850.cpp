#include <iostream>
using namespace std;

int main() {
    long long N;
    int K;
    cin >> N >> K;
    if ((N >> K) & 1) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}
