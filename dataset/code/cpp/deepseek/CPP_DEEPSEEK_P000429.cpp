#include <iostream>
using namespace std;

int main() {
    int N, target;
    cin >> N >> target;
    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < N; i++) {
        if (arr[i] == target) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}