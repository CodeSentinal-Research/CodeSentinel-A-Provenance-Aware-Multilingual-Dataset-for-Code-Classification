#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;
    int even = 0, odd = 0;
    if (N == 0) even = 1;
    while (N > 0) {
        int d = N % 10;
        if (d % 2 == 0) even++;
        else odd++;
        N /= 10;
    }
    cout << even << " " << odd << endl;
    return 0;
}
