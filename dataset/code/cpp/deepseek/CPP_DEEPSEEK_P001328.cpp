Here is the code for the given problem in C++. The code includes the necessary header files and the main function.

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + n);
    
    do {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    } while (next_permutation(arr, arr + n));
    
    return 0;
}
This code first reads the size of the array and the array elements. It then sorts the array and calculates all permutations using the `next_permutation` function provided by the `algorithm` library. For each permutation, it prints the elements of the array.