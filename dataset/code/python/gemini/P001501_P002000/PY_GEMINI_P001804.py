from typing import List

class Solution:
    def isSameBSTSeq(self, a: List[int], b: List[int]) -> bool:
        if len(a) != len(b):
            return False
        if not a:
            return True
        if a[0] != b[0]:
            return False

        left_a = [x for x in a[1:] if x < a[0]]
        right_a = [x for x in a[1:] if x > a[0]]
        left_b = [x for x in b[1:] if x < b[0]]
        right_b = [x for x in b[1:] if x > b[0]]

        return self.isSameBSTSeq(left_a, left_b) and self.isSameBSTSeq(right_a, right_b)