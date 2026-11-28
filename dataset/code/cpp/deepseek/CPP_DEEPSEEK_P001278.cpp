#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int max_from_end = arr[n - 1];
    int chunks = 0;

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] <= max_from_end)
            chunks++;
        else
            max_from_end = arr[i];
    }

    cout << chunks << endl;

    return 0;
}