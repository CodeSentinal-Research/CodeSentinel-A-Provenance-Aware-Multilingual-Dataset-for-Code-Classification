import sys
from collections import Counter

def solve():
    s1 = sys.stdin.readline().strip().split()
    s2 = sys.stdin.readline().strip().split()
    
    counter1 = Counter(s1)
    counter2 = Counter(s2)
    
    uncommon = []
    for word, count in counter1.items():
        if count == 1 and word not in counter2:
            uncommon.append(word)
    for word, count in counter2.items():
        if count == 1 and word not in counter1:
            uncommon.append(word)
            
    print(" ".join(sorted(uncommon)))

solve()

