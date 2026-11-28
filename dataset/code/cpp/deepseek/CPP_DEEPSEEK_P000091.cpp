#include <iostream>
using namespace std;

int main() {
    int n, r;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of r: ";
    cin >> r;
    
    int nPr = nPr(n, r);
    
    cout << "nPr is: " << nPr << endl;
    
    return 0;
}

int nPr(int n, int r) {
    if (r > n) {
        cout << "Invalid input. r > n" << endl;
        return -1;
    }
    if (n == 0 || r == 0 || n == 1) {
        return 1;
    }
    
    int result = n;
    for (int i = 1; i < r; i++) {
        result *= n - i;
    }
    
    return result;
}