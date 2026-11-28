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
    
    int max_diff = arr[1] - arr[0];
    int min_element = arr[0];
    
    for(int i = 1; i < n; i++) {
        if (arr[i] - min_element > max_diff) {
            max_diff = arr[i] - min_element;
        }
        if (arr[i] < min_element) {
            min_element = arr[i];
        }
    }
    
    cout << max_diff;
    return 0;
}

This program first reads the size of the array from the input. Then, it reads the elements of the array. In the main part of the program, it calculates the maximum difference and the smallest element in the array. It then updates the maximum difference and smallest element if necessary. Finally, it prints out the maximum difference.