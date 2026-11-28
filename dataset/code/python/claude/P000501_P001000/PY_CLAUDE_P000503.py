
s=input().strip();stk=[0]
for c in s:
    if c=='(': stk.append(0)
    else:
        v=stk.pop()
        stk[-1]+=max(2*v,1)
print(stk[0])
