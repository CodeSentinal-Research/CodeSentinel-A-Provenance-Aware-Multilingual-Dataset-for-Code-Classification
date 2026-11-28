#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;
    int pos = 1;
    while (!(N & 1)) {
        pos++;
        N >>= 1;
    }
    cout << pos << endl;
    return 0;
}
