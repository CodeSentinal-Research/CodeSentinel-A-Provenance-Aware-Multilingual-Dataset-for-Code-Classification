#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    int ones = 0, twos = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        ones = (ones ^ nums[i]) & ~twos;
        twos = (twos ^ nums[i]) & ~ones;
    }
    cout << ones << endl;
    return 0;
}
