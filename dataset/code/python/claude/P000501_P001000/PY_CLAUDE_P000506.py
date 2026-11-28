
expr=input().strip()
def calc(s, i):
    stk=[];num=0;sign='+'
    while i<len(s):
        c=s[i]
        if c.isdigit(): num=num*10+int(c)
        if c=='(':
            num,i=calc(s,i+1)
        if (not c.isdigit() and c!=' ') or i==len(s)-1:
            if sign=='+': stk.append(num)
            elif sign=='-': stk.append(-num)
            elif sign=='*': stk.append(stk.pop()*num)
            elif sign=='/': stk.append(int(stk.pop()/num))
            if c==')': return sum(stk),i
            sign=c;num=0
        i+=1
    return sum(stk),i
print(calc(expr,0)[0])
