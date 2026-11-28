import sys
from collections import Counter

def solve():
    s1 = sys.stdin.readline().strip()
    s2 = sys.stdin.readline().strip()
    
    if Counter(s1) == Counter(s2):
        print("YES")
    else:
        print("NO")

solve()

