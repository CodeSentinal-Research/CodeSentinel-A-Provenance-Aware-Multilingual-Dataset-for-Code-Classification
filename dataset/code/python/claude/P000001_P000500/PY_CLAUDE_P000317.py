
pattern=input().strip()
words=input().strip().split()
if len(pattern)!=len(words): print('No');exit()
mp={};mw={}
for p,w in zip(pattern,words):
    if mp.get(p,w)!=w or mw.get(w,p)!=p: print('No');exit()
    mp[p]=w;mw[w]=p
print('Yes')
