# problem title : Recursive Word Search
# Solve the stated task using standard input and standard output.
import sys
def word_search(board, word):
    n, m = len(board), len(board[0])
    def backtrack(r, c, idx):
        if idx == len(word): return True
        if r < 0 or r >= n or c < 0 or c >= m or board[r][c] != word[idx]: return False
        temp = board[r][c]
        board[r][c] = '#'
        res = (backtrack(r + 1, c, idx + 1) or
               backtrack(r - 1, c, idx + 1) or
               backtrack(r, c + 1, idx + 1) or
               backtrack(r, c - 1, idx + 1))
        board[r][c] = temp
        return res
    for i in range(n):
        for j in range(m):
            if backtrack(i, j, 0): return True
    return False
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        m = int(tokens[1])
        board = []
        idx = 2
        for _ in range(n):
            board.append([tokens[idx + j] for j in range(m)])
            idx += m
        word = tokens[idx]
        print("true" if word_search(board, word) else "false")
if __name__ == '__main__':
    main()
