
s=input().strip();stk=[]
for c in s:
    if c=='(': stk.append([])
    elif c==')':
        top=stk.pop()
        if stk: stk[-1].extend(reversed(top))
        else: stk.append(list(''.join(reversed(top))))
    else:
        if stk: stk[-1].append(c)
        else: stk.append([c])
print(''.join(stk[0]) if stk else '')
