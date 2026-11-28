# problem title : Rearrange Barcodes
# Solve the stated task using standard input and standard output.
from typing import List
from collections import Counter

class Solution:
    def rearrangeBarcodes(self, barcodes: List[int]) -> List[int]:
        count = Counter(barcodes)
        sorted_elements = []
        for val, cnt in count.most_common():
            sorted_elements.extend([val] * cnt)

        res = [0] * len(barcodes)
        res[::2] = sorted_elements[:(len(barcodes) + 1) // 2]
        res[1::2] = sorted_elements[(len(barcodes) + 1) // 2:]
        return res
