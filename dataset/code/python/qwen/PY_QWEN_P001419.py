import sys
from collections import Counter

def solve():
    s = sys.stdin.readline().strip()
    counter = Counter(s)
    # Sort by frequency desc, then char asc
    sorted_chars = sorted(counter.items(), key=lambda x: (-x[1], x[0]))
    result = ""
    for char, freq in sorted_chars:
        result += char * freq
    print(result)

solve()

