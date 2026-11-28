# problem title : Compare Version Numbers
# Compare version components numerically after removing leading zeros.
a=input().split('.'); b=input().split('.'); n=max(len(a),len(b))
for i in range(n):
    x=int(a[i]) if i<len(a) else 0; y=int(b[i]) if i<len(b) else 0
    if x!=y: print(1 if x>y else -1); break
else: print(0)
