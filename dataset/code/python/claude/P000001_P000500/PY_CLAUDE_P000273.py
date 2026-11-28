
s=input();stack=[];m={')':'(',']':'[','}':'{'}
for c in s:
    if c in '([{': stack.append(c)
    elif c in ')]}': 
        if not stack or stack[-1]!=m[c]: print('Invalid');exit()
        stack.pop()
print('Valid' if not stack else 'Invalid')
