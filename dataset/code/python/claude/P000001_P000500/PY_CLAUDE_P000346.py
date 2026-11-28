
s=input().strip();n=int(input())
words=[input().strip() for _ in range(n)]
def isSubseq(w,s):
    i=0
    for c in s:
        if i<len(w) and c==w[i]: i+=1
    return i==len(w)
best=''
for w in words:
    if isSubseq(w,s):
        if len(w)>len(best) or (len(w)==len(best) and w<best): best=w
print(best)
