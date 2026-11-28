#include <iostream>
using namespace std;

int findMax(int arr[], int size, int idx) {
    if(idx == size - 1) {
        return arr[0];
    }
    else {
        return max(arr[idx], findMax(arr, size, idx + 1));
    }
}

int main() {
    int size;
    cin >> size;
    int* arr = new int[size];
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    int result = findMax(arr, size, 0);
    cout << result;
    delete[] arr;
    return 0;
}