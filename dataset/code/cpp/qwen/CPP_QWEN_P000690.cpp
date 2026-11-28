#include <iostream>
using namespace std;
void decToBin(long long n) {
    if(n > 1) decToBin(n / 2);
    cout << (n % 2);
}
int main() {
    long long n; cin >> n;
    if(n == 0) cout << 0; else decToBin(n);
    cout << endl;
    return 0;
}
