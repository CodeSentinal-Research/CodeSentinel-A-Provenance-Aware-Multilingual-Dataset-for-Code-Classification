
s=input().strip()
n=int(input())
words=[input().strip() for _ in range(n)]
def isSubseq(w,s):
    i=0
    for c in s:
        if i<len(w) and c==w[i]: i+=1
    return i==len(w)
print(sum(isSubseq(w,s) for w in words))
