#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a non-negative integer: ";
    cin >> n;

    int count = 0;
    while(n > 0) {
        int digit = n % 10;
        if(digit % 2 == 0) {
            count++;
        }
        n /= 10;
    }

    cout << "Count of even digits: " << count << endl;

    return 0;
}