#include <iostream>
using namespace std;

bool predict_the_winner(int arr[], int n) {
    if(n == 1) {
        return true;
    }

    int total = 0;
    for(int i = 0; i < n; i++) {
        total += arr[i];
    }

    return (total % 2 == 0) ? true : false;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bool result = predict_the_winner(arr, n);

    if(result) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}