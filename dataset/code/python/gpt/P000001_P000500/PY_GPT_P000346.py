# problem title : Find the Longest Word in Dictionary
# Keep dictionary words that are subsequences, then choose maximum length and lexicographically smallest.
s=input(); words=input().split();
def sub(w):
    it=iter(s);return all(any(c==x for c in it) for x in w)
valid=[w for w in words if sub(w)];print(min(valid,key=lambda w:(-len(w),w)) if valid else '')
