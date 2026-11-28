
grid=[list(input()) for _ in range(9)]
def is_ok(r,c,ch):
    if ch in grid[r]: return False
    if ch in [grid[i][c] for i in range(9)]: return False
    br,bc=3*(r//3),3*(c//3)
    if ch in [grid[br+i][bc+j] for i in range(3) for j in range(3)]: return False
    return True
def solve():
    for r in range(9):
        for c in range(9):
            if grid[r][c]=='.':
                for d in '123456789':
                    if is_ok(r,c,d):
                        grid[r][c]=d
                        if solve(): return True
                        grid[r][c]='.'
                return False
    return True
solve()
for row in grid: print(*row)
