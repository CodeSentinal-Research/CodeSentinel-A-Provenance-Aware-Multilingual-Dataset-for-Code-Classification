
from typing import List

class Solution:
    def getMultiplicationTable(self, n: int, limit: int = 10) -> List[int]:
        return [n * i for i in range(1, limit + 1)]
