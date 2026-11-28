import sys
def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 2:
        r, c = int(lines[0]), int(lines[1])
        grid = []
        idx = 2
        for i in range(r):
            grid.append(lines[idx:idx+c])
            idx += c
        for j in range(c):
            print(' '.join(grid[i][j] for i in range(r)))
if __name__ == '__main__':
    main()