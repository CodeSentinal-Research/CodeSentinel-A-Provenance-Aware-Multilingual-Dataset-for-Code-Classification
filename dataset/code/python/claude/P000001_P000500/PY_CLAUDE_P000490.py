
def proc(s):
    stk=[]
    for c in s:
        if c=='#':
            if stk: stk.pop()
        else: stk.append(c)
    return ''.join(stk)
s=input();t=input()
print('true' if proc(s)==proc(t) else 'false')
