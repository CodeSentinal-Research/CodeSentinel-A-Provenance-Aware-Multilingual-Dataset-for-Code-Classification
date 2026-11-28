#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    int inclusive = 0, exclusive = 0;
    for(int i=0; i<n; i++) {
        int new_exclusive = max(inclusive, exclusive);
        inclusive = exclusive + arr[i];
        exclusive = new_exclusive;
    }
    
    int maxSum = max(inclusive, exclusive);
    cout << maxSum;
    return 0;
}