#include <iostream>
using namespace std;

int hcf(int a, int b) {
    while (b) { int t = b; b = a % b; a = t; }
    return a;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << hcf(a, b) << endl;
    return 0;
}
