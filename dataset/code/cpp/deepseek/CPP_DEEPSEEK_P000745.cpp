Here is the C++ code for the given problem.

#include <iostream>
using namespace std;

void insertionSort(int nums[], int n) {
    if (n <= 1)
        return;

    insertionSort(nums, n - 1);

    int key = nums[n - 1];
    int j = n - 2;

    while (j >= 0 && nums[j] > key) {
        nums[j + 1] = nums[j];
        j = j - 1;
    }

    nums[j + 1] = key;
}

void printArray(int nums[], int n) {
    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";
    cout << endl;
}

int main() {
    int nums[] = {12, 11, 13, 5, 6};
    int n = sizeof(nums) / sizeof(nums[0]);

    cout << "Given array is \n";
    printArray(nums, n);

    insertionSort(nums, n);

    cout << "\nSorted array is \n";
    printArray(nums, n);

    return 0;
}

In this code, the `insertionSort` function is recursive. The function takes an array and the size of the array as input. If the size of the array is less than or equal to 1, it returns. Otherwise, the function calls itself with the input array and the size decremented by 1.

In the recursive call, the function extracts the last element and inserts it in the correct position in the sorted array. The rest of the array is processed in reverse order.

The `printArray` function is used to print the array.

In the `main` function, the array is defined and the sizes of the array and the array are calculated. The given array is printed, the array is sorted using insertion sort, and then the sorted array is printed.