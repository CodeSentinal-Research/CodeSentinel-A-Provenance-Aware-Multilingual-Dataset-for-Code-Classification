Here is the C++ code:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    sort(arr.begin(), arr.end());

    auto lower = lower_bound(arr.begin(), arr.end(), x);
    auto upper = upper_bound(arr.begin(), arr.end(), x);

    if (lower - arr.begin() < (arr.end() - upper) / 2) {
        lower--;
    }

    return vector<int>(arr.begin() + (lower - arr.begin()), arr.begin() + lower + k);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 3;
    int x = 3;

    vector<int> result = findClosestElements(arr, k, x);

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}

This code first sorts the array, then uses two `lower_bound` and `upper_bound` functions to find the range of elements that are closest to the target. If the lower bound is closer to the target, it moves the lower bound one step towards the target, otherwise, it just keeps the lower bound. Then it returns the k closest elements.