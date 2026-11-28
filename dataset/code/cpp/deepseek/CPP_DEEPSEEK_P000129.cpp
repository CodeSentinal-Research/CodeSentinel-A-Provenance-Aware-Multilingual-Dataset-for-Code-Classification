Here is the code:

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreaterElement(vector<int> &nums) {
    stack<int> s;
    vector<int> result(nums.size(), -1);

    for (int i = 0; i < nums.size(); i++) {
        while (!s.empty() && nums[i] > s.top()) {
            result[s.top()] = nums[i];
            s.pop();
        }
        s.push(i);
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> result = nextGreaterElement(nums);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}

This code works by using a stack to keep track of the indices of the numbers. When a number is encountered, it pops all the numbers from the stack that are smaller than the current number, and then pushes the current number into the stack. The next greater element for each number is then stored in the result vector. The result vector is initialized with -1 for all elements.