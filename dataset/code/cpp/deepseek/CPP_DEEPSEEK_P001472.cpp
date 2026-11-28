#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void threeSum(int arr[], int n) {
    sort(arr, arr + n);

    for (int i = 0; i < n - 2; i++) {
        int a = arr[i];
        int start = i + 1;
        int end = n - 1;

        while (start < end) {
            if (a + arr[start] + arr[end] == 0) {
                cout << a << ", " << arr[start] << ", " << arr[end] << endl;
                start++;
                end--;

                while (start < end && arr[start] == arr[start - 1])
                    start++;
                while (start < end && arr[end] == arr[end + 1])
                    end--;
            }
            else if (a + arr[start] + arr[end] < 0)
                start++;
            else
                end--;
        }
    }
}

int main() {
    int arr[] = {-1, 0, 1, 2, -1, -4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "The three numbers sum to zero are: " << endl;
    threeSum(arr, n);

    return 0;
}
This code first sorts the input array. Then, for each element, it uses two pointers to find a pair whose sum is equal to the negative of the current element. The pointers are moved accordingly. If the sum is less than zero, the left pointer is moved right. If the sum is greater than zero, the right pointer is moved left. This is done to avoid duplicates.