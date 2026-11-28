Here's the code you need:

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] != 0) {
            arr[count++] = arr[i];
        }
    }

    while(count < n) {
        arr[count++] = 0;
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
This code reads an integer `n`, then it reads `n` integers into an array. Then, it moves all the non-zero elements to the beginning of the array and appends `n-count` zeros at the end. The final output is the array with all zeroes moved to the end.