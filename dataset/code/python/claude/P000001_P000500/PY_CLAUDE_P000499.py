
s=input().strip();stk=[]
for c in s:
    if stk and stk[-1]!=c and stk[-1].lower()==c.lower(): stk.pop()
    else: stk.append(c)
print(''.join(stk))
