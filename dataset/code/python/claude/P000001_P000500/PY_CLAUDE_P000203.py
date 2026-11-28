
n = int(input())
nums = list(map(int, input().split()))
from collections import Counter
c = Counter(nums)
print(c.most_common(1)[0][0])
