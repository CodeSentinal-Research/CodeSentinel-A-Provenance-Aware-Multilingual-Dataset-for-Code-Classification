
n,diff=map(int,input().split())
a=list(map(int,input().split()))
s=set(a)
for x in a:
    if x+diff in s and x+diff!=x: print('Yes');exit()
print('No')
