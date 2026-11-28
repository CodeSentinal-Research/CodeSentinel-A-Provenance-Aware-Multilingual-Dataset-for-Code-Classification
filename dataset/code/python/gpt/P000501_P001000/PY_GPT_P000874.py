# problem title : Decode XORed Permutation
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def decode(self, encoded: List[int]) -> List[int]:
        n = len(encoded) + 1
        total_xor = 0
        for i in range(1, n + 1):
            total_xor ^= i
        
        odd_xor = 0
        for i in range(1, len(encoded), 2):
            odd_xor ^= encoded[i]
            
        first = total_xor ^ odd_xor
        perm = [first]
        for x in encoded:
            perm.append(perm[-1] ^ x)
        return perm
