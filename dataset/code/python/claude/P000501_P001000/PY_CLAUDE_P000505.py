
expr=input().strip();stk=[];num=0;sign='+'
for i,c in enumerate(expr+'+'):
    if c.isdigit(): num=num*10+int(c)
    elif c in '+-*/':
        if sign=='+': stk.append(num)
        elif sign=='-': stk.append(-num)
        elif sign=='*': stk.append(stk.pop()*num)
        elif sign=='/': stk.append(int(stk.pop()/num))
        sign=c;num=0
print(sum(stk))
