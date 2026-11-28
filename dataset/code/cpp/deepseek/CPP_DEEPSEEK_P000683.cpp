#include <iostream>
using namespace std;

int power(int x, int n) {
    if(n == 0) {
        return 1;
    } else {
        return x * power(x, n - 1);
    }
}

int main() {
    int x, n;
    cout << "Enter the value of x: ";
    cin >> x;
    cout << "Enter the value of n: ";
    cin >> n;

    if(x < -100 || x > 100 || n < 0 || n > 30) {
        cout << "Invalid input. Please enter numbers in the range -100 <= x <= 100 and 0 <= n <= 30." << endl;
        return 0;
    }

    cout << "Result: " << power(x, n) << endl;

    return 0;
}