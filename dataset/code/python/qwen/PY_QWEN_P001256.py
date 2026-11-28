import sys
from collections import Counter

def solve():
    s = sys.stdin.readline().strip()
    counter = Counter(s)
    freqs = sorted(counter.values(), reverse=True)
    
    deletions = 0
    used_freqs = set()
    
    for f in freqs:
        while f > 0 and f in used_freqs:
            f -= 1
            deletions += 1
        if f > 0:
            used_freqs.add(f)
            
    print(deletions)

if __name__ == "__main__":
    solve()

