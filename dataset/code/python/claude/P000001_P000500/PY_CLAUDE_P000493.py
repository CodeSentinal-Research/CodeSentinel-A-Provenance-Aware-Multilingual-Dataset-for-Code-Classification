
s,k=input().split();k=int(k);stk=[]
for c in s:
    while k>0 and stk and stk[-1]>c: stk.pop();k-=1
    stk.append(c)
stk=stk[:len(stk)-k]
print(''.join(stk).lstrip('0') or '0')
