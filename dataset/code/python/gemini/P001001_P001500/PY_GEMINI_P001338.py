from typing import List

class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        res = []
        for length in range(len(str(low)), len(str(high)) + 1):
            for start in range(1, 10 - length + 1):
                num = 0
                for d in range(start, start + length):
                    num = num * 10 + d
                if low <= num <= high:
                    res.append(num)
        return res