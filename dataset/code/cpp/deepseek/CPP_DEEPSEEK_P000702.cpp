#include <iostream>
using namespace std;

int countOccurrences(int arr[], int n, int target) {
    if (n == 0) {
        return 0;
    }

    if (arr[0] == target) {
        return 1 + countOccurrences(arr + 1, n - 1, target);
    } else {
        return countOccurrences(arr + 1, n - 1, target);
    }
}

int main() {
    int arr[] = {1, 2, 3, 2, 2, 4, 2, 5, 2, 3, 2};
    int n = 11;
    int target = 2;
    cout << "Number of occurrences of " << target << " is " << countOccurrences(arr, n, target);
    return 0;
}