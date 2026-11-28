#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int min_len = arr[0].size(), idx = 0;
    for (int i = 1; i < n; i++) {
        if (a[i].size() < min_len) { min_len = a[i].size(); idx = i; }
    }
    cout << idx << endl;
    return 0;
}
