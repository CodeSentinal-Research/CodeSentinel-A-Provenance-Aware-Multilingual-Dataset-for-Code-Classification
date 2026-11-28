import sys

def solve():
    s = sys.stdin.readline().strip()
    imbalance = 0
    swaps = 0
    
    for char in s:
        if char == '[':
            imbalance += 1
        else:
            imbalance -= 1
        if imbalance == -1:
            swaps += 1
            imbalance = 1
            
    print(swaps)

if __name__ == "__main__":
    solve()

