# problem title : Find the Celebrity
# A celebrity is known by everyone and knows nobody; first find a candidate, then verify it.
n=int(input()); a=[list(map(int,input().split())) for _ in range(n)]; cand=0
for i in range(1,n):
    if a[cand][i]: cand=i
ok=all(a[i][cand] for i in range(n) if i!=cand) and all(a[cand][i]==0 for i in range(n) if i!=cand)
print(cand if ok else -1)
