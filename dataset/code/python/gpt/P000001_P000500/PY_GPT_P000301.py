# problem title : Restore IP Addresses
# Backtracking tries one, two, or three digits for each IPv4 segment.
s=input(); out=[]
def dfs(i,parts):
    if len(parts)==4:
        if i==len(s): out.append('.'.join(parts))
        return
    for j in range(i+1,min(len(s),i+3)+1):
        x=s[i:j]
        if (len(x)>1 and x[0]=='0') or int(x)>255: continue
        dfs(j,parts+[x])
dfs(0,[]); print(*out,sep='\n')
