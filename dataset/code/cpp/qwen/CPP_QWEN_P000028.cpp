#include <iostream>
using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
    long long res = 1;
    for (int i = 0; i < n; i++) res *= x;
    cout << res << endl;
    return 0;
}
