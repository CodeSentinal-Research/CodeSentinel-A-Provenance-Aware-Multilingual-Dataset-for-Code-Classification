import sys

def solve():
    n = int(sys.stdin.readline())
    
    def backtrack(current):
        if len(current) == n:
            print(current)
            return
        backtrack(current + '0')
        if not current or current[-1] != '1':
            backtrack(current + '1')
            
    backtrack("")

if __name__ == "__main__":
    solve()

