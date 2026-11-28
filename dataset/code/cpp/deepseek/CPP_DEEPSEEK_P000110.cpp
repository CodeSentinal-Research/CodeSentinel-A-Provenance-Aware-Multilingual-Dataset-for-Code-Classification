Here is the C++ solution:

#include <iostream>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == target) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
This program reads the size of the array and the target element, then reads the array elements. It then iterates over the array and increments a count each time it encounters the target element. Finally, it prints the count.