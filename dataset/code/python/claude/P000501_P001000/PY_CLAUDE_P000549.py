
n=int(input());inp=list(map(int,input().split()));out=list(map(int,input().split()))
stk=[];j=0
for v in inp:
    stk.append(v)
    while stk and j<n and stk[-1]==out[j]: stk.pop();j+=1
print('true' if not stk else 'false')
