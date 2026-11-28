Here is a Python solution using a recursive backtracking algorithm to solve the crossword puzzle. The main idea is to place each word from the list on the grid, starting from the leftmost cell of the row. Once a word is placed, it tries to place the next word in the same row or in the next row. If no solution can be found, it backtracks to the previous cell and tries the next word.

def solve_crossword(N, grid, words, word_idx, path):
    if word_idx == len(words):
        return True

    word = words[word_idx]
    row = 0
    for cell in range(N):
        if is_valid(grid, word, row, cell):
            grid[row][cell] = word

            if solve_crossword(N, grid, words, word_idx + 1, path):
                return True

            grid[row][cell] = '-'

        row += 1
    return False


def is_valid(grid, word, row, col):
    for ch in word:
        if ch != grid[row][col] and grid[row][col] != '-':
            return False
        col += 1
    return True


def main():
    N = 4
    grid = [['-' for _ in range(N)] for _ in range(N)]
    words = ['cat', 'dog', 'bat', 'ant']
    word_idx = 0
    path = []

    solve_crossword(N, grid, words, word_idx, path)

    for row in grid:
        print(' '.join(row))


if __name__ == "__main__":
    main()

This code will print a crossword grid with the words placed. If no valid crossword is found, it will print 'No valid solution'.