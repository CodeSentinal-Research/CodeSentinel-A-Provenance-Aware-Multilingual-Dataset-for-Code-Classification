#include <iostream>
using namespace std;

bool search(int arr[], int n, int target) {
    if (n == 0) {
        return false;
    }

    if (arr[0] == target) {
        return true;
    } else {
        return search(arr + 1, n - 1, target);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 5;

    cout << (search(arr, n, target) ? "true" : "false") << endl;

    return 0;
}