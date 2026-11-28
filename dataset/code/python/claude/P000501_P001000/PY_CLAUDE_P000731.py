
n=int(input());count=[0]
def solve(row,cols,d1,d2):
    if row==n: count[0]+=1;return
    for c in range(n):
        if c not in cols and row-c not in d1 and row+c not in d2:
            solve(row+1,cols|{c},d1|{row-c},d2|{row+c})
solve(0,set(),set(),set())
print(count[0])
