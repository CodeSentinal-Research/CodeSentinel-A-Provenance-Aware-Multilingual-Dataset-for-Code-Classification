import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    s = input_data[idx]; idx += 1
    n = int(input_data[idx]); idx += 1
    
    words = []
    for _ in range(n):
        words.append(input_data[idx]); idx += 1
        
    # Preprocess s for fast subsequence check
    # Next occurrence array
    next_occ = [[-1]*26 for _ in range(len(s)+1)]
    for i in range(len(s)-1, -1, -1):
        for j in range(26):
            next_occ[i][j] = next_occ[i+1][j]
        next_occ[i][ord(s[i])-ord('a')] = i
        
    count = 0
    for word in words:
        curr_idx = 0
        valid = True
        for c in word:
            if curr_idx >= len(s):
                valid = False
                break
            next_pos = next_occ[curr_idx][ord(c)-ord('a')]
            if next_pos == -1:
                valid = False
                break
            curr_idx = next_pos + 1
        if valid:
            count += 1
            
    print(count)

solve()

