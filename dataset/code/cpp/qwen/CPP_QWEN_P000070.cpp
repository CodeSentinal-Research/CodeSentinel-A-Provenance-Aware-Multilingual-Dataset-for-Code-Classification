#include <iostream>
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    bool valid = (a + b > c) && (a + c > b) && (b + c > a);
    cout << (valid ? "Valid" : "Invalid") << endl;
    return 0;
}
