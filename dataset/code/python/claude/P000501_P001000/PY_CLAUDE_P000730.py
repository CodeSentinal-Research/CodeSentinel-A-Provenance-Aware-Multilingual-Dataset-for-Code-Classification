
n=int(input());res=[]
def solve(row,cols,d1,d2,board):
    if row==n: res.append(board[:]);return
    for c in range(n):
        if c not in cols and row-c not in d1 and row+c not in d2:
            board.append('.'*c+'Q'+'.'*(n-c-1))
            solve(row+1,cols|{c},d1|{row-c},d2|{row+c},board)
            board.pop()
solve(0,set(),set(),set(),[])
for sol in res:
    for row in sol: print(row)
    print()
