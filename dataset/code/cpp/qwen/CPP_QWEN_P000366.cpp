#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int max_val = arr[0], idx = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > max_val) { max_val = a[i]; idx = i; }
    }
    cout << idx << endl;
    return 0;
}
