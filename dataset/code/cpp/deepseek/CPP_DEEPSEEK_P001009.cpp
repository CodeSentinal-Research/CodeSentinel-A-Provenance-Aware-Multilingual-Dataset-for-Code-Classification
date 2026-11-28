#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_heap(vector<int>& arr) {
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    make_heap(arr.begin(), arr.end());
    arr.erase(arr.begin());
    print_heap(arr);
    return 0;
}
This program will input the number of elements and then the elements themselves, then it will delete the root of the heap and print the rest of the heap. The 'make_heap' function from the algorithm library is used to rearrange the elements in the heap to satisfy the Max Heap property. The 'erase' function is used to remove the root element.