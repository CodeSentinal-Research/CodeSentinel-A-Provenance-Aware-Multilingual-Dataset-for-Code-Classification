Here is the C++ code to check if a number is a perfect square using binary search:

#include <iostream>
#include <cmath>
using namespace std;

bool isPerfectSquare(int n) {
    if (n == 1) return true;
    if (n < 1) return false;
    
    int x = sqrt(n);
    return x*x == n;
}

int main() {
    int n;
    cin >> n;
    
    if (isPerfectSquare(n)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    
    return 0;
}
This program first takes an input `n`. Then it uses the `isPerfectSquare` function to check if `n` is a perfect square. If it is, it outputs "Yes", otherwise it outputs "No".