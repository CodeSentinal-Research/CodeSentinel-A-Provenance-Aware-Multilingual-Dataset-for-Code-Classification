Here is the C++ code for the problem:

#include <iostream>
#include <algorithm>

using namespace std;

bool findTriplet(int arr[], int n, int sum) {
    sort(arr, arr + n);

    for (int i = 0; i < n - 1; i++) {
        int l = i + 1;
        int r = n - 1;
        while (l < r) {
            if (arr[i] + arr[l] + arr[r] == sum) {
                return true;
            }
            else if (arr[i] + arr[l] + arr[r] < sum) {
                l += 1;
            }
            else {
                r -= 1;
           
            }
        }
    }
    return false;
}

int main() {
    int n, sum;
    cin >> n >> sum;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (findTriplet(arr, n, sum)) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

    return 0;
}
This code first sorts the array and then uses two pointers approach to find a triplet with a sum equal to the given sum. The three pointers `l`, `i`, and `r` are initialized to the start, current, and end of the array, respectively. If the sum of the three numbers at indices `i`, `l`, and `r` is equal to the target sum, it returns `true`. If the sum is less than the target sum, it increases `l` to the next index; if the sum is greater, it decreases `r` to the previous index. This process is repeated until a triplet is found or the end of the array is reached. If no such triplet is found, it returns `false`.