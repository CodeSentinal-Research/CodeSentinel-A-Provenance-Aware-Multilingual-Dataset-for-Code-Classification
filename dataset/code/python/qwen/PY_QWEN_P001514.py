import sys

def solve():
    s = sys.stdin.readline().strip()
    n = len(s)
    
    left = 0
    max_len = 0
    adjacent_equal = 0
    
    for right in range(1, n):
        if s[right] == s[right-1]:
            adjacent_equal += 1
        while adjacent_equal > 1:
            if s[left+1] == s[left]:
                adjacent_equal -= 1
            left += 1
        max_len = max(max_len, right - left + 1)
        
    # Handle single char case
    if n == 0:
        print(0)
    else:
        print(max_len)

solve()

