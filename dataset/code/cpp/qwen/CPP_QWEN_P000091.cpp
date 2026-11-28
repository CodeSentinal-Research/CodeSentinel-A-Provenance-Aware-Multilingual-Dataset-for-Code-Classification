#include <iostream>
using namespace std;

long long nPr(int n, int r) {
    long long res = 1;
    for (int i = 0; i < r; i++) res *= (n - i);
    return res;
}

int main() {
    int n, r;
    cin >> n >> r;
    cout << nPr(n, r) << endl;
    return 0;
}
