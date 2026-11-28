#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;
    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }
    int dr = N % 9;
    if (dr == 0) dr = 9;
    cout << dr << endl;
    return 0;
}
