#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    long long currentSum = 0;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        currentSum += nums[i];
        if (currentSum < 0) count++;
    }
    
    cout << count << endl;
    return 0;
}
