import sys

def solve():
    s = sys.stdin.readline().strip()
    n = len(s)
    max_splits = 0
    
    def backtrack(start, used_substrings):
        nonlocal max_splits
        if start == n:
            max_splits = max(max_splits, len(used_substrings))
            return
        for end in range(start + 1, n + 1):
            sub = s[start:end]
            if sub not in used_substrings:
                used_substrings.add(sub)
                backtrack(end, used_substrings)
                used_substrings.remove(sub)
                
    backtrack(0, set())
    print(max_splits)

if __name__ == "__main__":
    solve()

