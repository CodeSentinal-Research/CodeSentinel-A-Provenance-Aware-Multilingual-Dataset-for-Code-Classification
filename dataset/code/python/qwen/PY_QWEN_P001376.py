import sys
from collections import defaultdict

def solve():
    input_data = sys.stdin.read().splitlines()
    if not input_data:
        return
    n = int(input_data[0])
    strs = input_data[1:1+n]
    
    anagram_map = defaultdict(list)
    for s in strs:
        key = tuple(sorted(s))
        anagram_map[key].append(s)
        
    groups = sorted(anagram_map.values(), key=lambda x: x[0])
    for group in groups:
        print(" ".join(sorted(group)))

solve()

