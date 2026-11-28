Here is the complete C++ code:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] != a[n + i]) return false;
    }
    return true;
}

void solve(vector<int>& a) {
    int n = a.size();
    if (n % 2 != 0) {
        cout << -1 << endl;
        return;
    }
    if (!check(a)) {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != a[n - i - 1]) {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        a[i] = a[n + i] / 2;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (a[i] != a[n - i - 1]) {
            cout << -1 << endl;
            return;
        }
    }
    cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    solve(a);
    return 0;
}

The code first reads the size of the array, and then the elements of the array. The solve function checks if the size of the array is even, if not, it prints -1. If the array is valid, it then checks if the array is a doubled array, and if not, it prints -1. If the array is valid, it then checks if the array is the result of a shuffle, and if not, it prints -1. If the array is valid, it then prints the original array.