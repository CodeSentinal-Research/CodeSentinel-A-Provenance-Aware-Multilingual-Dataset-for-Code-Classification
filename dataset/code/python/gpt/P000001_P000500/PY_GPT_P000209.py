# problem title : Rotate Matrix Elements
# Rotate each ring one step clockwise by moving its boundary values.
r,c=map(int,input().split()); a=[list(map(int,input().split())) for _ in range(r)]
for layer in range(min(r,c)//2):
    top,left=layer,layer; bottom,right=r-1-layer,c-1-layer
    prev=a[top+1][left]
    for i in range(left,right+1): prev,a[top][i]=a[top][i],prev
    for i in range(top+1,bottom+1): prev,a[i][right]=a[i][right],prev
    for i in range(right-1,left-1,-1): prev,a[bottom][i]=a[bottom][i],prev
    for i in range(bottom-1,top,-1): prev,a[i][left]=a[i][left],prev
for row in a: print(*row)
