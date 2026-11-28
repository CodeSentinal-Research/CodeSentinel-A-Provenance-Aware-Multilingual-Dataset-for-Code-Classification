#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int findGCD(vector<int>& nums) {
    int result = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        result = gcd(nums[i], result);
        if(result == 1) {
            return 1;
        }
    }
    return result;
}

int main() {
    int N;
    cin >> N;

    vector<int> nums(N);
    for(int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    cout << findGCD(nums) << endl;

    return 0;
}