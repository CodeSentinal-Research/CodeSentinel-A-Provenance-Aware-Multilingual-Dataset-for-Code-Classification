#include <iostream>
using namespace std;

int equilibrium(int arr[], int n) {
    int sum = 0;
    int left_sum = 0;

    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }

    for(int i = 0; i < n; i++) {
        sum -= arr[i];
        if(left_sum == sum) {
            return i+1;
        }
        left_sum += arr[i];
    }

    return -1;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int equilibrium_index = equilibrium(arr, n);

    if(equilibrium_index != -1) {
        cout << equilibrium_index;
    } else {
        cout << "No equilibrium point";
    }

    return 0;
}