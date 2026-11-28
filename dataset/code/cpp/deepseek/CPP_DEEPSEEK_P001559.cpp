#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long solve(vector<int>& arr, long long k) {
    long long count = 0;
    for (int i = 0; i < arr.size(); i++) {
        long long product = 1;
        for (int j = i; j < arr.size(); j++) {
            product *= arr[j];
            if (product >= k) break;
            count++;
        }
    }
    return count;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long count = solve(arr, k);
    cout << count << endl;
    return 0;
}