Here is the C++ code for the given problem. This code uses a sliding window approach to solve the problem. 

#include <iostream>
#include <unordered_set>
#include <deque>

using namespace std;

int countWindows(int arr[], int n, int k) {
    unordered_set<int> s;
    deque<int> d;
    int distinctCount = 0;

    for (int i = 0; i < n; i++) {
        s.insert(arr[i]);
        d.push_back(arr[i]);

        if (s.size() == k) {
            distinctCount++;

            if (d.front() == *s.begin()) {
                s.erase(d.front());
                d.pop_front();
            }
        }
    }

    return distinctCount;
}

int main() {
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << countWindows(arr, n, k);

    return 0;
}

This code reads the size of the array and the size of the window from the input. It then reads the array of integers from the input. It calls the `countWindows` function with these parameters and prints the return value.