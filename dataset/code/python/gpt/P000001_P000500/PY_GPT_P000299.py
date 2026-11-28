# problem title : Generate Parentheses
# Backtracking places an opening bracket while allowed, then closes it when valid.
n=int(input()); out=[]
def dfs(s,o,c):
    if len(s)==2*n: out.append(s); return
    if o<n: dfs(s+'(',o+1,c)
    if c<o: dfs(s+')',o,c+1)
dfs('',0,0); print(*out,sep='\n')
