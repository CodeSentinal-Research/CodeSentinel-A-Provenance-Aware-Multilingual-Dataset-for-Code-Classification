
r, c = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(r)]
def max_hist(h):
    stack=[]; mx=0
    for i,v in enumerate(h+[0]):
        while stack and h[stack[-1]]>=v:
            ht=h[stack.pop()]; w=i if not stack else i-stack[-1]-1
            mx=max(mx,ht*w)
        stack.append(i)
    return mx
hist=[0]*c
ans=0
for i in range(r):
    for j in range(c): hist[j]=hist[j]+1 if A[i][j] else 0
    ans=max(ans,max_hist(hist))
print(ans)
