Here is the C++ code:

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int xor_arr[n];
    xor_arr[0] = arr[0];
    for(int i = 1; i < n; i++) {
        xor_arr[i] = xor_arr[i-1] ^ arr[i];
    }
    
    for(int i = 0; i < n; i++) {
        cout << xor_arr[i] << " ";
    }
    cout << endl;

    return 0;
}
This code takes the size of the array as input, then it takes the elements of the array as input. It then calculates the prefix XOR array and prints it.