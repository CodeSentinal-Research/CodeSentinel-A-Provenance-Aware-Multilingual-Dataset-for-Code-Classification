#include <iostream>
using namespace std;

int main() {
    int a, d, n;
    cout << "Enter the first term: ";
    cin >> a;
    cout << "Enter the common difference: ";
    cin >> d;
    cout << "Enter the number of terms: ";
    cin >> n;

    int sum = (n / 2) * (2 * a + (n - 1) * d);

    cout << "The sum of the AP series is: " << sum << endl;

    return 0;
}