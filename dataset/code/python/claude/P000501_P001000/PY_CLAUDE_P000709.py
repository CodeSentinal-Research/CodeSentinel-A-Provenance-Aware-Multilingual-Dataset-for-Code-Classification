
from itertools import permutations
s=input().strip()
for p in sorted(set(''.join(x) for x in permutations(s))): print(p)
