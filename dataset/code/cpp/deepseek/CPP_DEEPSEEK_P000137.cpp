#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n+1];
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    int duplicate = -1;
    for(int i=1; i<=n; i++) {
        if(arr[abs(arr[i])] < 0) {
            duplicate = abs(arr[i]);
            break;
        }
        arr[abs(arr[i])] = -arr[abs(arr[i])];
    }

    cout << duplicate << endl;

    return 0;
}