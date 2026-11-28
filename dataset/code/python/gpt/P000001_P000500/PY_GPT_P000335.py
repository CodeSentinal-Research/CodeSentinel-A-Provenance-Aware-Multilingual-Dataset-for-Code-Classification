# problem title : Camelcase Matching
# A query matches if every uppercase pattern letter is present in order and no extra uppercase appears.
queries=input().split(); p=input(); out=[]
def match(q):
    i=0
    for ch in q:
        if i<len(p) and ch==p[i]:i+=1
        elif ch.isupper():return False
    return i==len(p)
print(*[str(match(q)) for q in queries])
