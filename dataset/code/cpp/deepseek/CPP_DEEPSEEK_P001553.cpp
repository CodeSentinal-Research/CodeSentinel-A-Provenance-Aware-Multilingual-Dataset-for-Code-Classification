#include <iostream>
#include <unordered_map>
#include <deque>
using namespace std;

int longestSubarray(int arr[], int n, int k) {
    unordered_map<int, int> freq;
    deque<int> dq;

    for (int i = 0; i < n; i++) {
        if (freq[arr[i]] > 0) {
            freq[arr[i]]++;
        } else {
            freq[arr[i]] = 1;
            while (!dq.empty() && freq[dq.front()] > 1) {
                freq[dq.front()]--;
                dq.pop_front();
            }
            if (dq.size() >= k) {
                freq[dq.front()]--;
                dq.pop_front();
            }
            dq.push_back(arr[i]);
        }
    }

    int ans = 0;
    while (!dq.empty()) {
        ans++;
        freq[dq.front()]--;
        dq.pop_front();
        if (freq[dq.front()] > 0) {
            freq[dq.front()]--;
            if (freq[dq.front()] == 0) {
                dq.pop_front();
            }
        }
    }

    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << longestSubarray(arr, n, k);
    return 0;
}