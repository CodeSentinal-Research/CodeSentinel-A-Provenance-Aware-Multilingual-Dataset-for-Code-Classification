#include <iostream>

using namespace std;

int main() {
    long long A, B, M;

    cout << "Enter values for A, B and M: ";
    cin >> A >> B >> M;

    long long result = (A - B) % M;

    cout << "Result: " << result << endl;

    return 0;
}