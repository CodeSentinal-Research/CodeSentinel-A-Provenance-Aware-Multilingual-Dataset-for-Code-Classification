import sys

def solve():
    pattern = sys.stdin.readline().strip()
    n = len(pattern) + 1
    
    result = []
    low = 1
    high = n
    
    for char in pattern:
        if char == 'I':
            result.append(low)
            low += 1
        else:
            result.append(high)
            high -= 1
            
    result.append(low)
    print(*result)

if __name__ == "__main__":
    solve()

