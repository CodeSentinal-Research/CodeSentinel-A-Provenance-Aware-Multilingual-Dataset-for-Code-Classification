import sys
from collections import Counter

def solve():
    s = sys.stdin.readline().strip()
    counter = Counter(s)
    
    balloon = {'b': 1, 'a': 1, 'l': 2, 'o': 2, 'n': 1}
    min_instances = float('inf')
    
    for char, req in balloon.items():
        if char in counter:
            min_instances = min(min_instances, counter[char] // req)
        else:
            min_instances = 0
            break
            
    print(min_instances)

solve()

