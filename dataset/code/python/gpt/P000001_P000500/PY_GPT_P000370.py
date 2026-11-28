# problem title : Search Duplicate Value
# A set records previously seen values; the first repeated value is the answer.
n=int(input());a=list(map(int,input().split()));seen=set();ans=-1
for x in a:
    if x in seen:ans=x;break
    seen.add(x)
print(ans)
