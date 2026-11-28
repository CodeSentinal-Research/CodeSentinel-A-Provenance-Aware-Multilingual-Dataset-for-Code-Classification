#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long s = sqrt(n);
    cout << (s * s == n ? "Perfect Square" : "Not Perfect Square") << endl;
    return 0;
}
