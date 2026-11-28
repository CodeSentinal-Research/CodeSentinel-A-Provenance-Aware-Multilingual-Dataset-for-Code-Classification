#include <iostream>
#include <vector>
using namespace std;

int minSwaps(vector<int>& arr, int n) {
    int count = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            int cycle_size = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = arr[j];
                cycle_size++;
            }
            count += (cycle_size - 1);
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << minSwaps(arr, n);
    return 0;
}