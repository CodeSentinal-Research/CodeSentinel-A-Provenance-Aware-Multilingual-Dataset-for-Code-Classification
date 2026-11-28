n = int(input())
emails = [input().strip() for _ in range(n)]
from collections import Counter
c = Counter(emails)
for e, count in c.items():
    if count > 1:
        print(e)
