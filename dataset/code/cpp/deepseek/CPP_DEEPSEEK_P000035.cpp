#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    int sum = 0;
    for(int i=1; i*i<=n; i++) {
        if(n % i == 0) {
            if(i * i != n)
                sum = sum + i + i;
            else
                sum = sum + i;
        }
    }

    if(sum == n)
        cout << "Perfect";
    else
        cout << "Not Perfect";

    return 0;
}