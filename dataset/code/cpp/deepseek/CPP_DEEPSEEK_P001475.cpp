Here is the C++ code for the given problem:

#include <iostream>
using namespace std;

void sortColors(int arr[], int n) {
    int count0 = 0, count1 = 0, count2 = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) count0++;
        else if (arr[i] == 1) count1++;
        else count2++;
    }
    
    for (int i = 0; i < n; i++) {
        if (count0 > 0) {
            arr[i] = 0;
            count0--;
        }
        else if (count1 > 0) {
            arr[i] = 1;
            count1--;
        }
        else {
            arr[i] = 2;
            count2--;
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sortColors(arr, n);
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}

This code first counts the number of 0s, 1s, and 2s in the input array. Then it reconstructs the array by replacing each integer with the corresponding count of 0s, 1s, and 2s, and finally prints the sorted array. The complexity of this solution is O(n) as we only traverse the array once.