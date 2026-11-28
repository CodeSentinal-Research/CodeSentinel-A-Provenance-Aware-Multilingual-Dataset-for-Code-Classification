Here is the C++ code that implements the problem:

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

long long countSubarrays(vector<int>& arr, int k) {
    int n = arr.size();
    long long res = 0;
    unordered_set<int> st;

    for (int i = 0; i < n; i++) {
        st.clear();
        int dist = 0;
        for (int j = i; j < n; j++) {
            if (st.find(arr[j]) == st.end()) {
                dist++;
                st.insert(arr[j]);
            } else {
                break;
            }
        }
        res += min(dist, k);
    }

    return res;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << countSubarrays(arr, k);

    return 0;
}

This C++ code uses the sliding window technique and a set data structure to solve the problem. The sliding window technique is used to iterate through the array and count the number of valid subarrays. The set data structure is used to store the distinct elements seen in the current subarray.

The code first reads the number of elements (n) and the maximum allowed distinct elements (k). Then, it reads the array of integers.

In the main function, the code calls the `countSubarrays` function to count the number of valid subarrays with at most k distinct elements. The result is printed out.