# problem title : Make The String Great
# A stack removes adjacent letters that differ only by case.
st=[]
for ch in input():
 if st and st[-1]!=ch and st[-1].lower()==ch.lower():st.pop()
 else:st.append(ch)
print(''.join(st))
