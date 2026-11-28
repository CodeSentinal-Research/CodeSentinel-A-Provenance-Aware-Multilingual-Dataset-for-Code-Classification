from collections import Counter

class Solution:
    def frequencySort(self, s: str) -> str:
        """Sorts the input array into ordered sequence."""
        count = Counter(s)
        return "".join(c * cnt for c, cnt in count.most_common())