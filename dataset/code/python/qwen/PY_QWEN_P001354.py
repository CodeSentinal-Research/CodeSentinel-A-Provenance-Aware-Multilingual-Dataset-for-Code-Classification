import sys

def solve():
    s = sys.stdin.readline().strip()
    n = len(s)
    
    def backtrack(start, seq):
        if start == n:
            return len(seq) >= 3
        for end in range(start + 1, n + 1):
            if end > start + 1 and s[start] == '0':
                break
            num = int(s[start:end])
            if num > 2**31 - 1:
                break
            if len(seq) < 2 or num == seq[-1] + seq[-2]:
                seq.append(num)
                if backtrack(end, seq):
                    return True
                seq.pop()
        return False
        
    if backtrack(0, []):
        print("Possible") # Or print the sequence
    else:
        print("IMPOSSIBLE")

if __name__ == "__main__":
    solve()

