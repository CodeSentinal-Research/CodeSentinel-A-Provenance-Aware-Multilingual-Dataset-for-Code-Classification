from typing import List

class Solution:
    def segregateEvenOdd(self, arr: List[int]) -> None:
        evens = sorted([x for x in arr if x % 2 == 0])
        odds = sorted([x for x in arr if x % 2 != 0])
        arr[:] = evens + odds