#include <iostream>

using namespace std;

bool isDivisibleBy11(long long N) {
    if (N % 11 == 0)
        return true;
    else
        return false;
}

int main() {
    long long N;
    cout << "Enter a number: ";
    cin >> N;
    
    if (isDivisibleBy11(N))
        cout << "True";
    else
        cout << "False";
    
    return 0;
}