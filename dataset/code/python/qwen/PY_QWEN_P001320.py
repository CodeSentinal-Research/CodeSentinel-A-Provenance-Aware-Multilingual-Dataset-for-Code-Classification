import sys

def solve():
    n = int(sys.stdin.readline())
    
    def backtrack(open_count, close_count, current):
        if len(current) == 2 * n:
            print(current)
            return
        if open_count < n:
            backtrack(open_count + 1, close_count, current + '(')
        if close_count < open_count:
            backtrack(open_count, close_count + 1, current + ')')
            
    backtrack(0, 0, "")

if __name__ == "__main__":
    solve()

