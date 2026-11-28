#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int temp = n, sum = 0, prod = 1;
    while (temp > 0) { sum += temp % 10; prod *= temp % 10; temp /= 10; }
    cout << (sum == prod ? "Spy" : "Not Spy") << endl;
    return 0;
}
