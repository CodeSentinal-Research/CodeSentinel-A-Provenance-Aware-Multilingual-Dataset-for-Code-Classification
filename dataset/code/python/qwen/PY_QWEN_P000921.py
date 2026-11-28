import sys
from collections import Counter
def solve():
    n = sys.stdin.read().split()[0]
    counts = Counter(n)
    for i in range(10):
        print(counts.get(str(i), 0), end=" ")
    print()
solve()
