# problem title : Remove All Adjacent Duplicates
# Remove adjacent equal characters with a stack; a new match can appear after each pop.
st=[]
for ch in input():
 if st and st[-1]==ch:st.pop()
 else:st.append(ch)
print(''.join(st))
