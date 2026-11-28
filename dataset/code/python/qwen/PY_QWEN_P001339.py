import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    strs = []
    for _ in range(n):
        strs.append(input_data[idx]); idx += 1
        
    max_len = 0
    
    def backtrack(index, current_set, current_len):
        nonlocal max_len
        if index == n:
            max_len = max(max_len, current_len)
            return
            
        # Skip current string
        backtrack(index + 1, current_set, current_len)
        
        # Include current string if no conflict
        chars = set(strs[index])
        if len(chars) == len(strs[index]) and not chars.intersection(current_set):
            backtrack(index + 1, current_set.union(chars), current_len + len(strs[index]))
            
    backtrack(0, set(), 0)
    print(max_len)

if __name__ == "__main__":
    solve()

