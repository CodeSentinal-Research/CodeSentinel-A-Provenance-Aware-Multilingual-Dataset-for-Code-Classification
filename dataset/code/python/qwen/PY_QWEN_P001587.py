import sys

def solve():
    s = sys.stdin.readline().strip()
    n = len(s)
    last_a = last_b = last_c = -1
    count = 0
    
    for i in range(n):
        if s[i] == 'a': last_a = i
        elif s[i] == 'b': last_b = i
        elif s[i] == 'c': last_c = i
        
        if last_a != -1 and last_b != -1 and last_c != -1:
            min_last = min(last_a, last_b, last_c)
            count += min_last + 1
            
    print(count)

solve()

