#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    int chunks = 0;
    int maxSoFar = 0;
    
    for (int i = 0; i < n; ++i) {
        maxSoFar = max(maxSoFar, nums[i]);
        if (maxSoFar == i) {
            chunks++;
        }
    }
    
    cout << chunks << endl;
    return 0;
}
