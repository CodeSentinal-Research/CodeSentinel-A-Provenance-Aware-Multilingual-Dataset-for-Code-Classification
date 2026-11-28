# problem title : Check If N and Its Double Exist
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        seen = set()
        for x in arr:
            if 2 * x in seen or (x % 2 == 0 and x // 2 in seen):
                return True
            seen.add(x)
        return False
