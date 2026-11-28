#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool prime = n > 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) { prime = false; break; }
    }
    cout << (prime ? "Prime" : "Not Prime") << endl;
    return 0;
}
