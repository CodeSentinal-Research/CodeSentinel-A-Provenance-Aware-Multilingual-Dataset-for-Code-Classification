import sys

def solve():
    s = sys.stdin.readline().strip()
    n = len(s)
    
    def is_palindrome(sub):
        return sub == sub[::-1]
        
    results = []
    
    def backtrack(start, path):
        if start == n:
            results.append(path[:])
            return
        for end in range(start + 1, n + 1):
            sub = s[start:end]
            if is_palindrome(sub):
                path.append(sub)
                backtrack(end, path)
                path.pop()
                
    backtrack(0, [])
    for res in results:
        print(" ".join(res))

if __name__ == "__main__":
    solve()

