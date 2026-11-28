#include <iostream>
using namespace std;

int digitalRoot(int N) {
    if (N == 0)
        return 0;
    else
        return (N % 9 == 0) ? 9 : (N % 9);
}

int main() {
    int N;
    cout << "Enter a non-negative integer: ";
    cin >> N;
    if(N < 0 || N > 10000000000000) {
        cout << "Invalid input. Please enter a non-negative integer within the constraints.";
        return 0;
    }
    cout << "The digital root is: " << digitalRoot(N) << endl;
    return 0;
}