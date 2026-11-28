# problem title : Count Smaller Elements on Right
# Merge-sort pairs by value while counting how many right-side values are smaller.
n=int(input());a=list(map(int,input().split()));ans=[0]*n
def sort(items):
 if len(items)<=1:return items
 m=len(items)//2;l=sort(items[:m]);r=sort(items[m:]);i=j=0;out=[]
 while i<len(l) and j<len(r):
  if l[i][1]<=r[j][1]:out.append(l[i]);i+=1
  else:ans[l[i][0]]+=len(r)-j;out.append(r[j]);j+=1
 return out+l[i:]+r[j:]
sort(list(enumerate(a)));print(*ans)
