#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printSubsequence(vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        int sum = nums[i];
        for (int j = i + 1; j < n; ++j) {
            if (sum + nums[j] == target) {
                cout << nums[i];
                for (int k = i + 1; k <= j; ++k) {
                    cout << " " << nums[k];
                }
                cout << endl;
                return;
            }
            sum += nums[j];
        }
    }
    cout << -1 << endl;
}

int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter target sum: ";
    cin >> target;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    printSubsequence(nums, target);

    return 0;
}