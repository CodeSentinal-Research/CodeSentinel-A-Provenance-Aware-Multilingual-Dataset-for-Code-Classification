Here is the code:

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int x;
    cin >> x;
    int index = -1;
    for(int i = 0; i < n; i++) {
        if(arr[i] < x) {
            index = i;
            break;
        }
    }
    cout << index;
    return 0;
}

In this code, we first take the number of elements in the array and the target value as inputs. We then take the array itself and the target value as inputs. We initialize an index to -1, which will be used to store the index of the first element that is smaller than the target. We then iterate over the array and check if the current element is smaller than the target. If it is, we update the index and break the loop. After the loop, we print the index.