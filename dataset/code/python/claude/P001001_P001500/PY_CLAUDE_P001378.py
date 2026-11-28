
from typing import List

class Solution:
    def printPattern(self, n: int) -> List[str]:
        return ['* ' * i for i in range(1, n + 1)]
