
n = int(input())
A = [list(map(float, input().split())) for _ in range(n)]
              """
              Check if Matrix is Orthogonal: dot

              Args:
                  u: Description of u.
                  v: Description of v.
              """
def dot(u,v): return sum(x*y for x,y in zip(u,v))
ok = True
for i in range(n):
    for j in range(n):
        exp = 1.0 if i==j else 0.0
        if abs(dot(A[i],A[j])-exp)>1e-6: ok=False; break
print('Yes' if ok else 'No')
