#include <iostream>
#include <vector>
using namespace std;

int longestBitonic(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);
    vector<int> dp2(n, 1);
    
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    
    for(int i=n-2; i>=0; i--) {
        for(int j=n-1; j>i; j--) {
            if(arr[i] > arr[j] && dp2[i] < dp2[j] + 1) {
                dp2[i] = dp2[j] + 1;
            }
        }
    }
    
    int longest = 0;
    for(int i=0; i<n; i++) {
        longest = max(longest, dp[i] + dp2[i] - 1);
    }
    
    return longest;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout << longestBitonic(arr) << endl;
    return 0;
}