Sure, here is the code for the problem:

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int kadane(const vector<int>& a) {
    int n = a.size();
    int max_so_far = INT_MIN, max_ending_here = 0,
    start =0, end = 0, s=0;

    for (int i=0; i< n; i++) {
        max_ending_here += a[i];

        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }

        if (max_ending_here < 0) {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    return max_so_far;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int wrap_sum = kadane(a);
    int total_sum = 0;
    for (int i = 0; i < n; i++) {
        total_sum += a[i];
    }
    int max_circular = max(wrap_sum, total_sum);
    cout << max_circular;
    return 0;
}

This program uses the Kadane's algorithm to find the maximum circular subarray sum. It first calculates the maximum sum of a non-circular subarray using the Kadane's algorithm. Then it calculates the total sum of the array and finds the maximum circular sum among the total sum and the maximum sum of the non-circular subarray. The time complexity of the program is O(n), where n is the size of the input array.