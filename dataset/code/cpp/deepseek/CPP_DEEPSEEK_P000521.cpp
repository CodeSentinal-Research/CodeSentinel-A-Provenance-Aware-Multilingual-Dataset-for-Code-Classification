Here is the C++ code for the problem:

#include <iostream>
#include <vector>

using namespace std;

int min_passes(int n, vector<int>& nums) {
    int passes = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] <= nums[i - 1]) {
            while (i > 0 && nums[i] <= nums[i - 1]) {
                nums.erase(nums.begin() + i);
                n--;
            }
            passes++;
        }
    }
    return passes;
}

int main() {
    int n;
    vector<int> nums;

    cin >> n;
    nums.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << min_passes(n, nums) << endl;

    return 0;
}
This code reads the number of elements and the elements themselves from the standard input, then calls the `min_passes` function to determine the minimum number of passes required to remove all elements from the array.