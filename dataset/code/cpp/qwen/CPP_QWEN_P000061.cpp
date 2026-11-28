#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    int count = 0;
    do {
        if ((n % 10) % 2 != 0) count++;
        n /= 10;
    } while (n > 0);
    cout << count << endl;
    return 0;
}
