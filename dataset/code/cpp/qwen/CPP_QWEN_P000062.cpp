#include <iostream>
using namespace std;

int fact(int n) {
    int f = 1;
    for (int i = 1; i <= n; i++) f *= i;
    return f;
}

int main() {
    int n;
    cin >> n;
    int temp = n, sum = 0;
    while (temp > 0) {
        sum += fact(temp % 10);
        temp /= 10;
    }
    cout << (sum == n ? "Strong" : "Not Strong") << endl;
    return 0;
}
