#include <iostream>

using namespace std;

int fibonacci(int N) {
    if(N==0) return 0;
    else if(N==1) return 1;
    else return fibonacci(N-1) + fibonacci(N-2);
}

int main() {
    int N;
    cout << "Enter a number: ";
    cin >> N;
    if(N>=0 && N<=35) {
        cout << fibonacci(N) << endl;
    }
    else {
        cout << "Invalid input, the input should be between 0 and 35" << endl;
    }
    return 0;
}