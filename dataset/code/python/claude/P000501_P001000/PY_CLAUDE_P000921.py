
n=int(input())
from collections import Counter
for d,cnt in sorted(Counter(str(abs(n))).items()): print(d,cnt)
