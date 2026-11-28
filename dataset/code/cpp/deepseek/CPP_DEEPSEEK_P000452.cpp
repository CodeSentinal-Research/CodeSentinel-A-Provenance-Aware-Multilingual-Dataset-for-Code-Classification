#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int res = 0;
    for(int i=0; i<n; i++) {
        res ^= arr[i];
    }

    cout << res;

    return 0;
}
This code reads an integer n followed by n integers into an array. It then uses XOR operation (^) to find the single occurring integer in the array. XOR operation is associative, which means that the order of operations is significant (i.e., the order of the inputs is not important). The result is the integer that appears only once in the array, which is then printed to the console.