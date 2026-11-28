#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int arr[N];
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }

    int L, R;
    cin >> L >> R;

    int sum = 0;
    for(int i=L; i<=R; i++) {
        sum += arr[i];
    }

    cout << sum << endl;

    return 0;
}