# problem title : Remove All Adjacent Duplicates in String II
# Store each character with its run count so groups of exactly K disappear immediately.
k=int(input()); st=[]
for ch in input():
    if st and st[-1][0]==ch: st[-1]=(ch,st[-1][1]+1)
    else: st.append((ch,1))
    if st[-1][1]==k: st.pop()
print(''.join(ch*c for ch,c in st))
