Here is the code:

#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int nums[100];
    cout << "Enter the number of elements: ";
    int n;
    cin >> n;
    cout << "Enter the elements: ";
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }
    quicksort(nums, 0, n-1);
    cout << "Sorted array: ";
    for(int i=0; i<n; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}

This code first takes the number of elements to be sorted and the elements themselves as input. Then, it uses the quicksort function to sort the array. The quicksort function is a recursive function that first picks an element as the pivot, partitions the array around the pivot, and then recursively sorts the sub-arrays around the pivot.