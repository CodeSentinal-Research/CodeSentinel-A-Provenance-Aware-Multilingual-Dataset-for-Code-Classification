#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    int arr[N];
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }

    int min1 = INT_MAX, min2 = INT_MAX;
    for(int i=0; i<N; i++) {
        if(arr[i] < min1) {
            min2 = min1;
            min1 = arr[i];
        } else if(arr[i] < min2) {
            min2 = arr[i];
        }
    }

    cout << min1*min2;

    return 0;
}