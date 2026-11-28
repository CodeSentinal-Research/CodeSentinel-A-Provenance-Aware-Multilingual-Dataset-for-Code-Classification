Here is the C++ code for your problem:

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

    cout << arr[0];
    for(int i=1; i<N; i++) {
        cout << " " << arr[i];
    }

    return 0;
}

This code reads the number of elements N, and then the elements themselves. It sorts the array in ascending order and then prints the sorted array in wave form.