Here is the C++ code that solves the problem:

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q, l, r;
    cin >> n >> q;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for(int i = 0; i < q; i++) {
        cin >> l >> r;
        int count = 0;
        for(int j = l; j <= r; j++) {
            if(nums[j] % 2 == 0) {
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}

This program reads the size of the array and the number of queries from the standard input, and then reads the array itself. It then loops through the queries, and for each query, it counts the number of even numbers between the given range in the array.