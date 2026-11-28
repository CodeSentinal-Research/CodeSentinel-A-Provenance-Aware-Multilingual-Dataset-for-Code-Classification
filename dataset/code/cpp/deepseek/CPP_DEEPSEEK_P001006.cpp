#include <iostream>
#include <vector>

using namespace std;

void verifyMinHeap(vector<int> &arr) {
    int n = arr.size();

    for(int i=n/2-1; i>=0; i--) {
        if(2*i+1 < n && arr[i] > arr[2*i+1]) {
            cout << "NO";
            return;
        }

        if(2*i+2 < n && arr[i] > arr[2*i+2]) {
            cout << "NO";
            return;
        }
    }

    cout << "YES";
    return;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    verifyMinHeap(arr);

    return 0;
}