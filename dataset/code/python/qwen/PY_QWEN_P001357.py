import sys

def solve():
    s = sys.stdin.readline().strip()
    n = len(s)
    
    def backtrack(first_len, second_len):
        if first_len + second_len > n:
            return False
        try:
            a = int(s[:first_len])
            b = int(s[first_len:first_len+second_len])
        except:
            return False
            
        pos = first_len + second_len
        while pos < n:
            c = a + b
            c_str = str(c)
            if not s[pos:].startswith(c_str):
                return False
            pos += len(c_str)
            a, b = b, c
        return True
        
    for i in range(1, n):
        for j in range(1, n - i + 1):
            if backtrack(i, j):
                print("YES")
                return
                
    print("NO")

if __name__ == "__main__":
    solve()

