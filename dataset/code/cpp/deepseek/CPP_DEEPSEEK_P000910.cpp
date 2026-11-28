#include <iostream>
using namespace std;

int main() {
    int n, r;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of r: ";
    cin >> r;

    int nPr = 1;
    for(int i = 1; i <= r; i++) {
        nPr *= (n - i + 1);
    }

    cout << "nPr = " << nPr << endl;
    return 0;
}