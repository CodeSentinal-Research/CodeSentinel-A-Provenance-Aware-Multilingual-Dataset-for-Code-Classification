#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    int minLen = INT_MAX;
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
        while(sum > x) {
            minLen = min(minLen, i - start + 1);
            sum -= arr[start];
            start++;
        }
    }
    
    if(minLen == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << minLen << endl;
    }

    return 0;
}