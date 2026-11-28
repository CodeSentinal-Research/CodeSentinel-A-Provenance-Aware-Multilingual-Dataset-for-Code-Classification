#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int d = arr[1] - arr[0];
    for(int i = 0; i < n; i++) {
        if (arr[i+1] - arr[i] != d) {
            cout << arr[i] + d;
            return 0;
        }
    }
    return 0;
}