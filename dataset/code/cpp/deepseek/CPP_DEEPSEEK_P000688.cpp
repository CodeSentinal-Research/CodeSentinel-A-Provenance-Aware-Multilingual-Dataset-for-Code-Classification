#include <iostream>
using namespace std;

long long digits(long long N) {
    if (N == 0)
        return 0;
    return 1 + digits(N / 10);
}

int main() {
    long long N;
    cout << "Enter a non-negative integer N: ";
    cin >> N;

    if (N < 0 || N > 10000000000000) {
        cout << "Invalid input, please enter a non-negative integer within the constraints (0 <= N <= 10^18)" << endl;
        return 0;
    }

    cout << "Number of digits in N's decimal representation: " << digits(N) << endl;

    return 0;
}