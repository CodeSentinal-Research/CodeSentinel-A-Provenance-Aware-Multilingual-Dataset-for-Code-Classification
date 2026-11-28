# problem title : Frequency Sort
# Solve the stated task using standard input and standard output.
from collections import Counter

class Solution:
    def frequencySort(self, s: str) -> str:
        count = Counter(s)
        return "".join(c * cnt for c, cnt in count.most_common())
