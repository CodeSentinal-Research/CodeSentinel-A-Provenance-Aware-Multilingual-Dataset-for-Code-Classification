import sys

def solve():
    s = sys.stdin.readline().strip()
    n = len(s)
    count = 0
    prev_count = 0
    
    i = 0
    while i < n:
        j = i
        while j < n and s[j] == s[i]:
            j += 1
        curr_count = j - i
        count += min(prev_count, curr_count)
        prev_count = curr_count
        i = j
        
    print(count)

solve()

