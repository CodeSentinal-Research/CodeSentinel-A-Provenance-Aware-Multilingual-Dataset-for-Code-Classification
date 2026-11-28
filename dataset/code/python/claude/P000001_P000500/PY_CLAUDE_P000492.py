
path=input().strip();parts=path.split('/');stk=[]
for p in parts:
    if p=='..':
        if stk: stk.pop()
    elif p and p!='.': stk.append(p)
print('/'+'/'.join(stk))
