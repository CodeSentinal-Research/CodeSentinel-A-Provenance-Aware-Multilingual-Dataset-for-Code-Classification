#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter a non-negative integer: ";
    cin >> N;
    if (N < 0 || N > 10^9) {
        cout << "Invalid input! Please enter a non-negative integer within the range [0, 10^9].";
        return 0;
    }
    cout << "The complement of base 10 integer is: " << (~N + 1);
    return 0;
}