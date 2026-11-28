#include <iostream>
using namespace std;

int main() {
    long long n;
    cout << "Enter a number: ";
    cin >> n;

    long long reversed = 0;

    while(n != 0) {
        reversed = reversed * 10 + n % 10;
        n = n / 10;
    }

    cout << "Reversed Number: " << reversed;

    return 0;
}