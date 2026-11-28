Here is the C++ code for the problem:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    K = N - K + 1; 
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater<int>()); 
    cout << arr[K - 1] << endl; 
    return 0;
}
This code first reads the number of elements N and the value of K, then reads the N elements of the array. It then sorts the array in descending order using the `sort` function from the `algorithm` library. The Kth largest element is then printed, but adjusted for 1-indexing (i.e., if K is 1, the Kth element is the last element).