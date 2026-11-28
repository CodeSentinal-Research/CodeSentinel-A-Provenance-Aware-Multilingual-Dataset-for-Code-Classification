Here is the code for the given problem in C++:

#include <iostream>
using namespace std;

void decreaseKey(int arr[], int i, int newVal, int n) {
    if (newVal > arr[i]) {
        cout << "New value is greater than current value. So no change required.\n";
        return;
    }

    arr[i] = newVal;

    while (i != 0 && arr[i] < arr[(i - 1) / 2]) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void printHeap(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n, arr[100000], i, newVal;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> i >> newVal;

    decreaseKey(arr, i, newVal, n);

    printHeap(arr, n);

    return 0;
}

This code firstly takes an array and an index, and a new value. Then it decreases the value of the key at the given index to the new value. If the new value is greater than the current value, no change is made and the program prints a message saying "New value is greater than current value. So no change required."

After updating the key, the code then traverses up the tree from the updated node and fixes the violated property.

Finally, the heap is printed.