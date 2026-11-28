Here is the code:

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

void findPairs(int n, int target, vector<int>& nums) {
    unordered_set<int> elements;
    for (int i = 0; i < n; i++) {
        if (elements.find(target - nums[i]) != elements.end()) {
            cout << nums[i] << " " << target - nums[i] << endl;
        } else {
            elements.insert(nums[i]);
        }
    }
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    findPairs(n, target, nums);
    return 0;
}

This program first reads the number of elements and the target sum from the input. Then it reads the elements themselves. For each element, it checks if there is another element in the set that adds up to the target sum. If the element is found in the set, it prints the pair. If not, it adds the element to the set.