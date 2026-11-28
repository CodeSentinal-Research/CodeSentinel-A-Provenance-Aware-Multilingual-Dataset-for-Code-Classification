#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> nums(N);
    for (int i = 0; i < N; ++i) cin >> nums[i];
    
    long long g = nums[0];
    for (int i = 1; i < N; ++i) {
        g = __gcd(g, nums[i]);
    }
    cout << g << endl;
    return 0;
}
