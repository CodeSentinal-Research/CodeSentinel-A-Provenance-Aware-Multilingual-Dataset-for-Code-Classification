#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max_length = 0;
    int cur_length = 1;
    int cur_product = 1;

    for(int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            cur_product *= arr[i];
        } else if (arr[i] == 0) {
            cur_product = 1;
        } else {
            int temp = cur_product;
            cur_product /= arr[i];
            if (temp == 1) {
                cur_length = 1;
            } else {
                cur_length = max(cur_length, (int)ceil((double)cur_product / temp));
            }
        }

        max_length = max(max_length, cur_length);
    }

    cout << max_length;

    return 0;
}