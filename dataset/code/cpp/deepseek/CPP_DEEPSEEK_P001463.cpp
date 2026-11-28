#include <iostream>
using namespace std;

int main() {
    int N, val;
    cin >> N >> val;
    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] != val) {
            arr[count] = arr[i];
            count++;
        }
    }
    cout << count << '\n';
    for (int i = 0; i < count; i++) {
        cout << arr[i] << ' ';
    }
    return 0;
}