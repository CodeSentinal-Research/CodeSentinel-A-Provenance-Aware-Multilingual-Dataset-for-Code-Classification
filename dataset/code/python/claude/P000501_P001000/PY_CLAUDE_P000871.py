
l,r=int(input()),int(input())
ans=l
while ans&r!=ans: ans&=r
print(ans&~(ans^(ans&r)))  

l2,r2=l,r
shift=0
while l2!=r2: l2>>=1;r2>>=1;shift+=1
print(l2<<shift)
