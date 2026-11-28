#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int i = 0; i < 32; i++) {
        int count = 0;
        for (int j = 0; j < nums.size(); j++) {
            if ((nums[j] & (1 << i)) != 0) {
                count++;
            }
        }
        if (count % 3 == 1) {
            result |= (1 << i);
        }
    }
    if (result >= 2147483648) {
        result -= 4294967296;
    }
    return result;
}

int main() {
    vector<int> nums = {1, 2, 2, 3, 3, 3, 4};
    int result = singleNumber(nums);
    cout << result << endl;
    return 0;
}