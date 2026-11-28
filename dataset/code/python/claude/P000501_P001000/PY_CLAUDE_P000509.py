
s=input().strip();stk=[]
for c in s:
    if c.isdigit():
        if stk and not stk[-1].isdigit(): stk.pop()
    else: stk.append(c)
print(''.join(stk))
