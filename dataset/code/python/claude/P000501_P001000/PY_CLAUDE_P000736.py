
n,k=int(input()),int(input())
def solve(n,k):
    if n==1: return 0
    parent=solve(n-1,(k+1)//2)
    return parent if k%2==1 else 1-parent
print(solve(n,k))
