
tokens=input().split();stk=[]
for t in tokens:
    if t in '+-*/':
        b,a=stk.pop(),stk.pop()
        if t=='+': stk.append(a+b)
        elif t=='-': stk.append(a-b)
        elif t=='*': stk.append(a*b)
        else: stk.append(int(a/b))
    else: stk.append(int(t))
print(stk[0])
