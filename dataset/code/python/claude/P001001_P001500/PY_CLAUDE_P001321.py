
from typing import List

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        phone = ['', '', 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
        result = []

        def bt(idx, curr):
            if idx == len(digits):
                result.append(curr)
                return
            for c in phone[int(digits[idx])]:
                bt(idx + 1, curr + c)

        bt(0, '')
        return result
