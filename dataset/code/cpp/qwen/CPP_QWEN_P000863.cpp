#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    int xorAll = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        xorAll ^= nums[i];
    }
    
    int setBit = xorAll & -xorAll;
    int a = 0, b = 0;
    for (int num : nums) {
        if (num & setBit) a ^= num;
        else b ^= num;
    }
    cout << a << " " << b << endl;
    return 0;
}
