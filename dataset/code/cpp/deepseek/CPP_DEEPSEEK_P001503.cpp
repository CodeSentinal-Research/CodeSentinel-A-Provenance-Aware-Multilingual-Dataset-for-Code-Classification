#include <iostream>
#include <vector>
using namespace std;

int minimumSwaps(vector<int>& arr, int k) {
    int n = arr.size();
    int count = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] == 1) {
            count++;
        }
    }
    if(count < k) {
        return -1;
    }
    int k_count = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] == 1) {
            k_count++;
            if(k_count == k) {
                int swap_count = 0;
                while(arr[i] != 1) {
                    swap(arr[i], arr[i-1]);
                    swap_count++;
                    i--;
                }
                return swap_count;
            }
        }
    }
    return -1;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout << minimumSwaps(arr, k);
    return 0;
}