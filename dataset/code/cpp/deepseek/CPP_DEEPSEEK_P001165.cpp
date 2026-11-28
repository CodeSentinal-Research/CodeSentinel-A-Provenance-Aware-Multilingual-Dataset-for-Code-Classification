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

    int max_product = arr[0];
    int min_product = arr[0];
    int global_max = arr[0];

    for(int i = 1; i < n; i++) {
        if(arr[i] < 0) {
            swap(max_product, min_product);
        }

        max_product = max(arr[i], max_product * arr[i]);
        min_product = min(arr[i], min_product * arr[i]);

        global_max = max(global_max, max_product);
    }

    cout << global_max << endl;

    return 0;
}