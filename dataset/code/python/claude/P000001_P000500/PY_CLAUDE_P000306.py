
expr=input().strip()
stk=[];num=0;op='+'
for i,c in enumerate(expr):
    if c.isdigit(): num=num*10+int(c)
    if (not c.isdigit() and c!=' ') or i==len(expr)-1:
        if op=='+': stk.append(num)
        elif op=='-': stk.append(-num)
        elif op=='*': stk.append(stk.pop()*num)
        elif op=='/': stk.append(int(stk.pop()/num))
        op=c;num=0
print(sum(stk))
