Here is the C++ code for the problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long lcm(long long a, long long b) {
    return (a * b) / __gcd(a, b);
}

long long findLCM(vector<int>& nums) {
    long long result = 1;
    for (int i = 0; i < nums.size(); i++) {
        result = lcm(result, nums[i]);
        result %= 1000000007;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << findLCM(nums);
    return 0;
}
This code firstly defines a helper function `lcm(a, b)` to calculate the least common multiple of `a` and `b`. Then it defines the main function `findLCM(nums)` to find the least common multiple of all elements in `nums`. It also handles input and output.