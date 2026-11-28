#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for(int i = 0; i < n; i++) {
        if(arr[i] <= 0) {
            arr[i] = 1;
        }
    }

    for(int i = 0; i < n; i++) {
        if(abs(arr[i]) - 1 < n && arr[abs(arr[i]) - 1] > 0) {
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        }
    }

    for(int i = 0; i < n; i++) {
        if(arr[i] > 0) {
            cout << (i + 1) << endl;
            break;
        }
    }
    
    return 0;
}