
n=int(input());prices=list(map(int,input().split()))
res=prices[:];stk=[]
for i in range(n):
    while stk and prices[stk[-1]]>=prices[i]:
        res[stk.pop()]-=prices[i]
    stk.append(i)
print(*res)
