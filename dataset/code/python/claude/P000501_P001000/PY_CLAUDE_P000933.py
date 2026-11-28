
n=int(input());A=[list(map(int,input().split())) for _ in range(n)]
ident=[[1 if i==j else 0 for j in range(n)] for i in range(n)]
print('true' if A==ident else 'false')
