#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    int max_val = arr[n-1];
    int min_val = arr[0];
    int min_ops = max_val - min_val;

    for(int i=n-1; i>0; i--) {
        if(arr[i] < arr[i-1]) {
            int ops = max_val - arr[i];
            if(ops < min_ops) {
                min_ops = ops;
            }
        }
    }

    cout << min_ops;
    return 0;
}
This program works by first sorting the array in ascending order. The maximum element in the array (max_val) is then compared with the minimum element in the array (min_val). The difference between the two is the minimum number of operations required to minimize the maximum element.

Then, for each element in the array from the end to the beginning, if the current element is less than the previous one, the number of operations needed to get the maximum element to the current element is compared with the minimum operations required so far. If the current operations required is less, the minimum operations required is updated.

Finally, the minimum operations required is printed.