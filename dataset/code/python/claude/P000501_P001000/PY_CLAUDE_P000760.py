
n=int(input())
from itertools import combinations
for combo in combinations(range(1,10),n): print(''.join(map(str,combo)))
