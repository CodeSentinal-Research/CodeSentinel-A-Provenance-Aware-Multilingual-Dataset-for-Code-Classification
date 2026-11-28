# problem title : Count Even and Odd Digits
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def evenOddBit(self, n: int) -> List[int]:
        even = 0
        odd = 0
        i = 0
        while n > 0:
            if n & 1:
                if i % 2 == 0:
                    even += 1
                else:
                    odd += 1
            n >>= 1
            i += 1
        return [even, odd]
