
n=int(input());sr=int(input());sc=int(input())
board=[[-1]*n for _ in range(n)];board[sr][sc]=0
moves=[(2,1),(2,-1),(-2,1),(-2,-1),(1,2),(1,-2),(-1,2),(-1,-2)]
def ok(r,c):
    return 0<=r<n and 0<=c<n and board[r][c]==-1
def degree(r,c):
    return sum(1 for dr,dc in moves if ok(r+dr,c+dc))
def solve(r,c,move):
    if move==n*n: return True
    nexts=[(degree(r+dr,c+dc),r+dr,c+dc) for dr,dc in moves if ok(r+dr,c+dc)]
    for _,nr,nc in sorted(nexts):
        board[nr][nc]=move;solve_res=solve(nr,nc,move+1)
        if solve_res: return True
        board[nr][nc]=-1
    return False
if solve(sr,sc,1):
    for row in board: print(*row)
else: print(-1)
