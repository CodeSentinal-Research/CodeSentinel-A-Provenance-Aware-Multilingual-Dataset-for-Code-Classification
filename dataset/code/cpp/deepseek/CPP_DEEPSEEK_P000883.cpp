#include <iostream>
using namespace std;

int main() {
    long long N;
    cout << "Enter a non-negative integer N: ";
    cin >> N;
    
    if(N < 0 || N > 1000000000000000) {
        cout << "Invalid input!";
        return 0;
    }
    
    long long product = 1;
    while(N != 0) {
        product *= N % 10;
        N /= 10;
    }
    
    cout << "Product of digits: " << product << endl;
    return 0;
}