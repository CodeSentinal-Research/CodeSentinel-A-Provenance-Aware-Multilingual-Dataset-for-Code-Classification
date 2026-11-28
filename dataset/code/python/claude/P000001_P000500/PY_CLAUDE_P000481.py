
n=int(input());ops=[input().strip() for _ in range(n)];stk=[]
for op in ops:
    if op=='+': stk.append(stk[-1]+stk[-2])
    elif op=='D': stk.append(stk[-1]*2)
    elif op=='C': stk.pop()
    else: stk.append(int(op))
print(sum(stk))
