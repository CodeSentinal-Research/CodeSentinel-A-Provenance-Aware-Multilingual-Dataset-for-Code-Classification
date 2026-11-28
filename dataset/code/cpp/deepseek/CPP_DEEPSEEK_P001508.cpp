#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    unordered_map<int, int> freq;
    int start = 0, max_freq = 0, max_baskets = 0;
    for (int end = 0; end < N; end++) {
        freq[arr[end]]++;
        if (freq[arr[end]] == 1) {
            max_freq = max(max_freq, freq[arr[end]]);
        }
        if (freq[arr[end]] == 2) {
            while (freq[arr[end]] > 2) {
                freq[arr[start]]--;
                start++;
            }
        }
        max_baskets = max(max_baskets, end - start + 1);
    }
    cout << max_baskets;
    return 0;
}
This C++ solution uses two pointers and a hash map (unordered_map) to solve the problem. The start pointer moves along the array, and the end pointer also moves. The hash map stores the frequency of each fruit type in the array.

If the frequency of a fruit type is 1, it means the fruit type is not in any basket yet. So we update the max_freq to be max of max_freq and the frequency of the fruit type.

If the frequency of a fruit type is 2, it means the fruit type is already in a basket. So we move the start pointer to the right until the frequency of the fruit type is 2.

At the end of the loop, the max_baskets is the maximum number of fruits that can be collected in two baskets.