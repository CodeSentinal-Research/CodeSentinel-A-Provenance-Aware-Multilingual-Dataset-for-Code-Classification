#include <iostream>
using namespace std;

int main() {
    long long N;
    cout << "Enter a number: ";
    cin >> N;

    if (N < 0 || N > 1000000000000) {
        cout << "Invalid input! Please enter a number between 0 and 10^18." << endl;
        return 0;
    }

    long long num_of_digits = 0;
    if (N == 0) {
        num_of_digits = 1;
    } else {
        while (N > 0) {
            N /= 10;
            num_of_digits++;
        }
    }

    cout << "Number of digits: " << num_of_digits << endl;
    return 0;
}