
expr=input().strip()
stack=[];num=0;sign=1;res=0
for c in expr+' ':
    if c.isdigit(): num=num*10+int(c)
    elif c in '+-':
        res+=sign*num;num=0;sign=1 if c=='+' else -1
    elif c=='(':
        stack.append(res);stack.append(sign);res=0;sign=1
    elif c==')':
        res+=sign*num;num=0
        res*=stack.pop();res+=stack.pop()
print(res)
