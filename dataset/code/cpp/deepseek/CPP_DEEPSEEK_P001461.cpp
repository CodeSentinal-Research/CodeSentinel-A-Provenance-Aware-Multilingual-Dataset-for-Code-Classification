#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, target;
    cin >> N >> target;

    vector<int> nums(N);
    for(int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int left = 0, right = N - 1;
    while(left < right) {
        if (nums[left] + nums[right] == target) {
            cout << left + 1 << " " << right + 1;
            return 0;
        } else if (nums[left] + nums[right] < target) {
            left++;
        } else {
            right--;
        }
    }

    return 0;
}