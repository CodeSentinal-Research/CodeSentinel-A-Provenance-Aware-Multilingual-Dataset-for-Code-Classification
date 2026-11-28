#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

const long long MOD = 1e9 + 7;

long long lcm_mod(long long a, long long b) {
    return (a / __gcd(a, b)) % MOD * (b % MOD) % MOD;
}

int main() {
    int N;
    cin >> N;
    vector<long long> nums(N);
    for (int i = 0; i < N; ++i) cin >> nums[i];
    
    long long l = nums[0];
    for (int i = 1; i < N; ++i) {
        l = lcm_mod(l, nums[i]);
    }
    cout << l << endl;
    return 0;
}
