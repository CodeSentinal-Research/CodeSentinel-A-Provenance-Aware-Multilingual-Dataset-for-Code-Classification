import sys

def solve():
    n = int(sys.stdin.readline())
    
    def is_safe(board, row, col):
        for i in range(row):
            if board[i] == col or abs(board[i] - col) == abs(i - row):
                return False
        return True
        
    def backtrack(row, board):
        if row == n:
            return 1
        count = 0
        for col in range(n):
            if is_safe(board, row, col):
                board[row] = col
                count += backtrack(row + 1, board)
        return count
        
    print(backtrack(0, [0]*n))

if __name__ == "__main__":
    solve()

