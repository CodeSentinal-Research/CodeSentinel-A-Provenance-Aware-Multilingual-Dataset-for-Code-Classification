#include <vector>
#include <algorithm>

class Solution {
    int getHeight(std::vector<int> arr) {
        if (arr.empty()) return 0;
        int root = arr[0];
        std::vector<int> left, right;
        for (size_t i = 1; i < arr.size(); i++) {
            if (arr[i] < root) left.push_back(arr[i]);
            else right.push_back(arr[i]);
        }
        return 1 + std::max(getHeight(left), getHeight(right));
    }
public:
    int heightOfBST(std::vector<int>& preorder) {
        return getHeight(preorder);
    }
};