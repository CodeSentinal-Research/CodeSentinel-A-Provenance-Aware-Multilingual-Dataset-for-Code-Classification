
a,b=input().split()
if a=='0' or b=='0': print('0');exit()
m,n=len(a),len(b)
pos=[0]*(m+n)
for i in range(m-1,-1,-1):
    for j in range(n-1,-1,-1):
        mul=(ord(a[i])-48)*(ord(b[j])-48)
        p1,p2=i+j,i+j+1
        total=mul+pos[p2]
        pos[p2]=total%10;pos[p1]+=total//10
res=''.join(str(x) for x in pos).lstrip('0') or '0'
print(res)
