#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int arr[N];
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int len = 1;
    for(int i = 1; i < N; i++) {
        if(arr[i] != arr[i-1]) {
            arr[len] = arr[i];
            len++;
        }
    }
    cout << len << endl;
    for(int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
This C++ code reads the number of elements and the sorted array from the input, and then calculates the new length of the array after removing the duplicates. It then prints the new length and the modified array.