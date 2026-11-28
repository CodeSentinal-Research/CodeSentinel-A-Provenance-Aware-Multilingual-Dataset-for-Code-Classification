import sys

def solve():
    s1 = sys.stdin.readline().strip()
    s2 = sys.stdin.readline().strip()
    
    n = len(s1)
    if n != len(s2):
        print("NO")
        return
        
    from functools import lru_cache
    
    @lru_cache(None)
    def is_scramble(a, b):
        if a == b:
            return True
        if sorted(a) != sorted(b):
            return False
            
        for i in range(1, len(a)):
            if (is_scramble(a[:i], b[:i]) and is_scramble(a[i:], b[i:])) or \
               (is_scramble(a[:i], b[-i:]) and is_scramble(a[i:], b[:-i])):
                return True
        return False
        
    print("YES" if is_scramble(s1, s2) else "NO")

if __name__ == "__main__":
    solve()

