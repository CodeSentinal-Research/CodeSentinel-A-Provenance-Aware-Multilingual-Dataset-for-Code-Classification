#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> duplicates;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] == nums[j]) {
                duplicates.push_back(nums[i]);
                break;
            }
        }
    }
    for (int i = 0; i < duplicates.size(); i++) {
        cout << duplicates[i] << " ";
    }
    return 0;
}