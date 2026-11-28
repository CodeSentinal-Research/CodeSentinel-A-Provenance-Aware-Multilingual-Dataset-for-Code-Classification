
n=int(input())
from collections import defaultdict
g=defaultdict(list)
for _ in range(n):
    w=input();g[''.join(sorted(w))].append(w)
for grp in g.values(): print(' '.join(grp))
