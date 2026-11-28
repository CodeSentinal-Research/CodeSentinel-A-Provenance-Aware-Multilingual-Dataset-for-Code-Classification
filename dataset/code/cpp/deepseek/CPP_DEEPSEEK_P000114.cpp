#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int arr[N];
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }

    for(int i=0; i<G; i++) {
        if (i < K) {
            int temp = arr[i];
            arr[i] = arr[N - K + i];
            arr[N - K + i] = temp;
        } else {
            int temp = arr[i];
            arr[i] = arr[i - K];
            arr[i - K] = temp;
        }
    }

    for(int i=0; i<N; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}