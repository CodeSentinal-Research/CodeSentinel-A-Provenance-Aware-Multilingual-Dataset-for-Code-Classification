# problem title : Next Greater Element I
# A decreasing monotonic stack stores candidates for the next greater element.
n=int(input());a=list(map(int,input().split()));m=int(input());b=list(map(int,input().split()));ng={};st=[]
for x in b:
 while st and st[-1]<x:ng[st.pop()]=x
 st.append(x)
print(*(ng.get(x,-1) for x in a))
