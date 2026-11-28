#include <iostream>
#include <vector>

using namespace std;

int findFirstOccurrence(int n, vector<int>& arr, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    vector<int> arr;
    int x;

    cin >> n;
    arr = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> x;

    int result = findFirstOccurrence(n, arr, x);
    cout << result << endl;

    return 0;
}