import sys

def solve():
    s = sys.stdin.readline().strip()
    if not s:
        return
        
    max_len = 0
    best_char = ''
    
    curr_len = 1
    curr_char = s[0]
    
    for i in range(1, len(s)):
        if s[i] == s[i-1]:
            curr_len += 1
        else:
            if curr_len > max_len or (curr_len == max_len and curr_char < best_char):
                max_len = curr_len
                best_char = curr_char
            curr_len = 1
            curr_char = s[i]
            
    if curr_len > max_len or (curr_len == max_len and curr_char < best_char):
        max_len = curr_len
        best_char = curr_char
        
    print(best_char, max_len)

solve()

