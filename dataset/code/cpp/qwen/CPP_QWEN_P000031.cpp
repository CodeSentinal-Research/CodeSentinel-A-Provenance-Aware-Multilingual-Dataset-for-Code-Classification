#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int orig = n, sum = 0, digits = 0, temp = n;
    while (temp > 0) { digits++; temp /= 10; }
    temp = n;
    while (temp > 0) {
        sum += pow(temp % 10, digits);
        temp /= 10;
    }
    cout << (sum == orig ? "Armstrong" : "Not Armstrong") << endl;
    return 0;
}
