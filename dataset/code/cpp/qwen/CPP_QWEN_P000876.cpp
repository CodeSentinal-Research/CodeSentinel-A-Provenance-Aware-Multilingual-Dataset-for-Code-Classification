#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int mask = 1;
    while (mask <= N) mask <<= 1;
    mask -= 1;
    cout << (N ^ mask) << endl;
    return 0;
}
