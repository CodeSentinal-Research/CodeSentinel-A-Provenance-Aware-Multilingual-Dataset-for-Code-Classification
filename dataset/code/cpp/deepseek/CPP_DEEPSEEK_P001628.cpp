#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int len = 0, sum = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] > 0) {
            sum += arr[i];
        } else {
            if (len < sum) {
                len = sum;
            }
            sum = 0;
        }
    }
    if (len < sum) {
        len = sum;
    }
    cout << (len > 0 ? len : 0) << endl;
    return 0;
}