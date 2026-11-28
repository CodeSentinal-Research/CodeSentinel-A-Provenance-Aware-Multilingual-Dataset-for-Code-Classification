# problem title : Baseball Game Score
# Stack operations model the baseball score history exactly.
n=int(input());ops=input().split();st=[]
for op in ops:
 if op=='+':st.append(st[-1]+st[-2])
 elif op=='D':st.append(2*st[-1])
 elif op=='C':st.pop()
 else:st.append(int(op))
print(sum(st))
