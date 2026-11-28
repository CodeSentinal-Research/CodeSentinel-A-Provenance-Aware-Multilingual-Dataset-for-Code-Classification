import sys

def solve():
    s = sys.stdin.readline().strip()
    n = len(s)
    low = 0
    high = n
    result = []
    
    for char in s:
        if char == 'I':
            result.append(low)
            low += 1
        else:
            result.append(high)
            high -= 1
            
    result.append(low)
    print(*result)

solve()

