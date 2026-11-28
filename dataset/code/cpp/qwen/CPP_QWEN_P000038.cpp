#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double p, r, t;
    cin >> p >> r >> t;
    cout << p * pow(1 + r / 100.0, (int)t) - p << endl;
    return 0;
}
