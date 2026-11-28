# problem title : Simplify Path
# Stack directory names while ignoring repeated slashes, dots, and parent moves.
p=input(); st=[]
for x in p.split('/'):
    if x in ('','.'): continue
    if x=='..':
        if st: st.pop()
    else: st.append(x)
print('/'+'/'.join(st))
