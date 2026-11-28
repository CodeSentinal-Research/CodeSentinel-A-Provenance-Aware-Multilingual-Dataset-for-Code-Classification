Here is the C++ code:

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    int arr[N];
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+N);

    int max_product = arr[N-1] * arr[N-2];

    cout << max_product;

    return 0;
}

This code first reads the number N of elements in the array. It then reads N integers into the array. The array is sorted in ascending order. The maximum product of two elements is the product of the two largest elements in the sorted array. The largest product is printed to the console.