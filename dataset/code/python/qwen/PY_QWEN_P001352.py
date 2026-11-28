import sys

def solve():
    s = sys.stdin.readline().strip()
    n = len(s)
    
    def backtrack(start, prev_val):
        if start == n:
            return True
        for end in range(start + 1, n + 1):
            val = int(s[start:end])
            if prev_val is None or val == prev_val - 1:
                if backtrack(end, val):
                    return True
        return False
        
    # Try splitting first number
    for end in range(1, n):
        first_val = int(s[:end])
        if backtrack(end, first_val):
            print("YES")
            return
            
    print("NO")

if __name__ == "__main__":
    solve()

