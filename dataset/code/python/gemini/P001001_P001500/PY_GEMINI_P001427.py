from collections import defaultdict

class Solution:
    def countLargestGroup(self, n: int) -> int:
        groups = defaultdict(int)
        for i in range(1, n + 1):
            s = sum(int(d) for d in str(i))
            groups[s] += 1
        max_size = max(groups.values())
        return sum(1 for cnt in groups.values() if cnt == max_size)