
n,m=map(int,input().split());mat=[list(map(int,input().split())) for _ in range(n)];t=int(input())
r,c=0,m-1
while r<n and c>=0:
    if mat[r][c]==t: print('true');exit()
    elif mat[r][c]>t: c-=1
    else: r+=1
print('false')
