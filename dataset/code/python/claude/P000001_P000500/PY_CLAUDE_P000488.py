
rows,cols=map(int,input().split())
mat=[input().split() for _ in range(rows)]
h=[0]*cols;ans=0
for r in range(rows):
    for c in range(cols):
        h[c]=h[c]+1 if mat[r][c]=='1' else 0

    stk=[];row_max=0;hh=h+[0]
    for i,v in enumerate(hh):
        while stk and hh[stk[-1]]>v:
            ht=hh[stk.pop()]
            w=i if not stk else i-stk[-1]-1
            row_max=max(row_max,ht*w)
        stk.append(i)
    ans=max(ans,row_max)
print(ans)
