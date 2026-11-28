#include <iostream>
using namespace std;

bool checkDivisibilityBy9(long long N) {
    if (N % 9 == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    long long N;
    cout << "Enter an integer: ";
    cin >> N;
    
    if (checkDivisibilityBy9(N)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    
    return 0;
}