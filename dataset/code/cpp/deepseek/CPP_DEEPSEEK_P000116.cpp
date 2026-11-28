#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n+1];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int total = n+1;
    int totalSum = total*(total+1)/2;
    int arrSum = 0;

    for(int i=0; i<n; i++) {
        arrSum += arr[i];
    }

    cout << totalSum - arrSum;

    return 0;
}