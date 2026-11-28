# problem title : Remove All Adjacent Duplicates in String
# A stack removes the previous character whenever two adjacent characters match.
st=[]
for ch in input():
    if st and st[-1]==ch:st.pop()
    else:st.append(ch)
print(''.join(st))
