#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    int even_count = 0;
    int odd_count = 0;

    while(n > 0) {
        int digit = n % 10;
        n /= 10;

        if(digit % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    cout << even_count << " " << odd_count << endl;

    return 0;
}