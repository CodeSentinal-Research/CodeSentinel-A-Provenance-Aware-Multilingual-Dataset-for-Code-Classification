#include <iostream>
using namespace std;

int findFirstNegative(int N, int arr[]) {
    for (int i = 0; i < N; i++) {
        if (arr[i] < 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int result = findFirstNegative(N, arr);
    cout << result << endl;
    return 0;
}