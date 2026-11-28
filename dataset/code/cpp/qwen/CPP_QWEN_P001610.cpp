#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    vector<long long> leftProd(n, 1);
    vector<long long> rightProd(n, 1);
    
    for (int i = 1; i < n; ++i) {
        leftProd[i] = leftProd[i-1] * nums[i-1];
    }
    for (int i = n - 2; i >= 0; --i) {
        rightProd[i] = rightProd[i+1] * nums[i+1];
    }
    
    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << " ";
        cout << leftProd[i] * rightProd[i];
    }
    cout << endl;
    return 0;
}
