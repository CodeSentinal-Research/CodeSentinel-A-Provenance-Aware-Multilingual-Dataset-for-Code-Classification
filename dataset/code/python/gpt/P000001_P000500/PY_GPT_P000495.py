# problem title : Online Stock Span
# The stack stores previous prices with their accumulated spans.
st=[];out=[]
for x in map(int,input().split()):
 span=1
 while st and st[-1][0]<=x:span+=st.pop()[1]
 st.append((x,span));out.append(span)
print(*out)
