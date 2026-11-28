
n,m=map(int,input().split());board=[list(input()) for _ in range(n)];word=input().strip()
def dfs(r,c,i,vis):
    if i==len(word): return True
    if r<0 or r>=n or c<0 or c>=m or (r,c) in vis or board[r][c]!=word[i]: return False
    vis.add((r,c))
    for dr,dc in [(-1,0),(1,0),(0,-1),(0,1)]:
        if dfs(r+dr,c+dc,i+1,vis): vis.remove((r,c));return True
    vis.remove((r,c));return False
print('true' if any(dfs(r,c,0,set()) for r in range(n) for c in range(m)) else 'false')
