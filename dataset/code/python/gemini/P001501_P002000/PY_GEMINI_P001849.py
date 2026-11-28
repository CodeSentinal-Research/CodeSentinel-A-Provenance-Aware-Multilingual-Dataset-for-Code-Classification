from typing import List

class Solution:
    def heightOfBST(self, preorder: List[int]) -> int:
        def get_height(arr):
            if not arr:
                return 0
            root = arr[0]
            left = [x for x in arr[1:] if x < root]
            right = [x for x in arr[1:] if x > root]
            return 1 + max(get_height(left), get_height(right))

        return get_height(preorder)