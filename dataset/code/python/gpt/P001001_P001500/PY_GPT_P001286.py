# problem title : Bag Filling with Additional Rocks
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def maximumBags(self, capacity: List[int], rocks: List[int], additionalRocks: int) -> int:
        remaining = sorted(c - r for c, r in zip(capacity, rocks))
        full_bags = 0

        for rem in remaining:
            if additionalRocks >= rem:
                additionalRocks -= rem
                full_bags += 1
            else:
                break

        return full_bags
