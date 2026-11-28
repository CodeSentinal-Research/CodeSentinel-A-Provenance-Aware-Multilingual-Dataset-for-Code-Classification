import sys
def main():
    lines = sys.stdin.read().split()
    if lines:
        n = int(lines[0])
        grid = []
        idx = 1
        for i in range(n):
            grid.append([int(x) for x in lines[idx:idx+n]])
            idx += n
        rotated = [[grid[n-1-j][i] for j in range(n)] for i in range(n)]
        for row in rotated:
            print(' '.join(str(x) for x in row))
if __name__ == '__main__':
    main()