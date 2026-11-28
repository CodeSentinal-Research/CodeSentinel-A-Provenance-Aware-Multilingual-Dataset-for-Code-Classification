#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter a positive integer: ";
    cin >> N;
    if (N <= 0 || N > 10000) {
        cout << "Invalid input";
        return 0;
    }
    int sum = 0;
    for (int i = 2; i <= N; i += 2) {
        sum += i;
    }
    cout << "The sum of the first " << N << " even numbers is " << sum;
    return 0;
}