# problem title : Generate Gray Code
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def grayCode(self, n: int) -> List[int]:
        return [i ^ (i >> 1) for i in range(1 << n)]
