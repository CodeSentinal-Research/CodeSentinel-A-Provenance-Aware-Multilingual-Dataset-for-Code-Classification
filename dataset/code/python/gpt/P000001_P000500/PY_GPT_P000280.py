# problem title : Valid Anagram after Removing One Character
# After deleting at most one character from either string, their frequency maps must match.
a=input(); b=input()
def ok(x,y):
    from collections import Counter
    d=Counter(x)-Counter(y); e=Counter(y)-Counter(x)
    return sum(d.values())<=1 and sum(e.values())<=1
print("Yes" if ok(a,b) else "No")
