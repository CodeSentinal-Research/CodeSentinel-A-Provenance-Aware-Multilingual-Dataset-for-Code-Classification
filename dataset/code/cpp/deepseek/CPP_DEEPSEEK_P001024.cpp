Here is the required C++ code:

#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int i;
    cin >> i;
    if (i == 0) {
        if (N < 2) {
            cout << -1 << endl;
        } else {
            cout << arr[i + 1] << endl;
        }
    } else {
        if (i == N - 1) {
            if (N < 2) {
                cout << -1 << endl;
            } else {
                cout << arr[i - 1] << endl;
            }
        } else {
            cout << arr[i - 1] << " " << arr[i + 1] << endl;
        }
    }
    return 0;
}

In this code, we first take the number of elements in the array and the index of the node as input. We then take the array elements as input. The index is used to access the node's left and right children. If the index is 0, the left child does not exist (because there's no previous node), and we print -1 for the right child. If the index is N-1, the right child does not exist, and we print -1 for the left child. For all other indices, we print the left child and right child.