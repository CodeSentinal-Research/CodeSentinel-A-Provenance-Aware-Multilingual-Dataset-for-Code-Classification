Here is the C++ code for your problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), [](int a, int b){
        return a % 2 == b % 2;
    });

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

This program first reads the number of elements `n` and then the array elements. The `sort` function from the Standard Template Library (STL) is used with a custom comparator that sorts numbers based on whether they are even or odd. The `%` operator is used to determine if a number is even or odd.