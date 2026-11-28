import sys
from collections import Counter

def solve():
    s = sys.stdin.readline().strip()
    counter = Counter(s)
    stack = []
    seen = set()
    
    for char in s:
        counter[char] -= 1
        if char in seen:
            continue
        while stack and stack[-1] > char and counter[stack[-1]] > 0:
            seen.remove(stack.pop())
        stack.append(char)
        seen.add(char)
        
    print("".join(stack))

if __name__ == "__main__":
    solve()

