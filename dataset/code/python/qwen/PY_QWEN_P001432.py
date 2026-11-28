import sys
from collections import Counter

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    dominoes = []
    for _ in range(n):
        u = int(input_data[idx]); idx += 1
        v = int(input_data[idx]); idx += 1
        dominoes.append((min(u, v), max(u, v)))
        
    counter = Counter(dominoes)
    pairs = 0
    for count in counter.values():
        pairs += count * (count - 1) // 2
        
    print(pairs)

solve()

