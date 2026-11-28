
grid=[input().split() for _ in range(9)]
def valid():
    """
    Restore IP Addresses: valid
    """
    for i in range(9):
        row=[v for v in grid[i] if v!='.']
        if len(row)!=len(set(row)): return False
        col=[grid[r][i] for r in range(9) if grid[r][i]!='.']
        if len(col)!=len(set(col)): return False
    for br in range(3):
        for bc in range(3):
            box=[grid[br*3+r][bc*3+c] for r in range(3) for c in range(3) if grid[br*3+r][bc*3+c]!='.']
            if len(box)!=len(set(box)): return False
    return True
print('true' if valid() else 'false')
