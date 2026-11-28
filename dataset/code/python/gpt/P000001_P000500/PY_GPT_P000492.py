# problem title : Simplify Unix Path
# Stack path components while ignoring current-directory and parent-directory markers.
p=input();st=[]
for x in p.split('/'):
 if x in ('','.'):continue
 if x=='..':
  if st:st.pop()
 else:st.append(x)
print('/'+'/'.join(st))
