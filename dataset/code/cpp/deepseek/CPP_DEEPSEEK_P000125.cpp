#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(int target, vector<int>& nums) {
    unordered_map<int, int> indices;
    for (int i = 0; i < nums.size(); ++i) {
        if (indices.find(target - nums[i]) != indices.end()) {
            return {indices[target - nums[i]], i};
        }
        indices[nums[i]] = i;
    }
    return {-1, -1};
}

int main() {
    int target;
    vector<int> nums;

    int N;
    cin >> N;

    cin >> target;

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    vector<int> indices = twoSum(target, nums);

    cout << indices[0] << " " << indices[1] << endl;

    return 0;
}