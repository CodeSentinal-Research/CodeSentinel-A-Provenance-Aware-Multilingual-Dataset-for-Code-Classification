Here is the C++ code that fulfills the problem constraints:

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cin >> q;
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        int count = 0;
        for(int j = l; j <= r; j++) {
            if(nums[j] > 0) {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}

This code first reads the number of integers and the number of queries, then reads the integers and the ranges for the queries. For each query, it iterates over the range and increments a counter if the number at the current index is positive. Finally, it prints the count.