# problem title : Longest Consecutive Sequence
# A set lets us start only at values that have no predecessor.
n=int(input()); a=list(map(int,input().split())); s=set(a); best=0
for x in s:
    if x-1 not in s:
        y=x
        while y in s: y+=1
        best=max(best,y-x)
print(best)
