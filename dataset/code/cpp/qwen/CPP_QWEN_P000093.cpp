#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, r, n;
    cin >> a >> r >> n;
    if (r == 1) cout << a * n << endl;
    else cout << a * (pow(r, n) - 1) / (r - 1) << endl;
    return 0;
}
