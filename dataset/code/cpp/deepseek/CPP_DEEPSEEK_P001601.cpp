Here is the code:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q, l, r;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < q; i++) {
        cin >> l >> r;
        cout << count(arr.begin() + l - 1, arr.begin() + r, 0) << endl;
    }
    return 0;
}

This program takes an array of integers and multiple range queries, and outputs the number of zeros in each specified range.

First, it reads the size of the array and the number of queries. Then, it reads the array itself. After that, for each query, it reads the start and end indices of the range, and then it counts the number of zeros in that range using the `count` function from the algorithm library.

Please note that the indices in C++ start from 0, so the index `l-1` refers to the first element, and `r` refers to the element right after the last element in the range.