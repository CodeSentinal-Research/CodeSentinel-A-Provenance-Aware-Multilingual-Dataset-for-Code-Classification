import sys

def solve():
    s = sys.stdin.readline().strip()
    n = len(s)
    results = []
    
    def backtrack(start, parts):
        if start == n and len(parts) == 4:
            results.append(".".join(parts))
            return
        if len(parts) >= 4:
            return
            
        for length in range(1, 4):
            if start + length > n:
                break
            segment = s[start:start+length]
            if (len(segment) > 1 and segment[0] == '0') or int(segment) > 255:
                continue
            parts.append(segment)
            backtrack(start + length, parts)
            parts.pop()
            
    backtrack(0, [])
    for res in results:
        print(res)

if __name__ == "__main__":
    solve()

