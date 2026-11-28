import sys

def solve():
    s = sys.stdin.readline().strip()
    n = len(s)
    
    char_index = [-1] * 128
    left = 0
    max_len = 0
    
    for right in range(n):
        char = s[right]
        if char_index[ord(char)] >= left:
            left = char_index[ord(char)] + 1
        char_index[ord(char)] = right
        max_len = max(max_len, right - left + 1)
        
    print(max_len)

solve()

