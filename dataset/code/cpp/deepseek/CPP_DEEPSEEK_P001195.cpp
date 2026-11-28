#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int arr[N];
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int inc = arr[0], dec = -arr[0];
    for(int i = 1; i < N; i++) {
        int inc_new = max(dec + arr[i], inc);
        int dec_new = max(inc - arr[i], dec);

        inc = inc_new;
        dec = dec_new;
    }

    cout << max(inc, dec);
    return 0;
}