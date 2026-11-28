#include <iostream>
using namespace std;

bool isHarshad(long long n) {
    int sum = 0;
    long long temp = n;
    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }
    return n % sum == 0;
}

int main() {
    long long n;
    cout << "Enter an integer: ";
    cin >> n;
    if (isHarshad(n))
        cout << "Yes, " << n << " is a Harshad number." << endl;
    else
        cout << "No, " << n << " is not a Harshad number." << endl;
    return 0;
}