import sys

def solve():
    n = int(sys.stdin.readline())
    
    def is_safe(board, row, col):
        for i in range(row):
            if board[i] == col or abs(board[i] - col) == abs(i - row):
                return False
        return True
        
    def backtrack(row, board, results):
        if row == n:
            results.append(board[:])
            return
        for col in range(n):
            if is_safe(board, row, col):
                board[row] = col
                backtrack(row + 1, board, results)
                
    results = []
    backtrack(0, [0]*n, results)
    
    print(len(results))
    # Printing all configurations is complex and might exceed output limits for large N, 
    # but problem asks for it. For N<=14 it's manageable.
    for res in results:
        print(" ".join(str(c+1) for c in res))

if __name__ == "__main__":
    solve()

