# problem title : Trapping Rain Water
# Two pointers trap water using the smaller boundary because the other side is already bounded.
h=list(map(int,input().split()));l=0;r=len(h)-1;lm=rm=0;ans=0
while l<=r:
 if h[l]<=h[r]:
  lm=max(lm,h[l]);ans+=lm-h[l];l+=1
 else:
  rm=max(rm,h[r]);ans+=rm-h[r];r-=1
print(ans)
