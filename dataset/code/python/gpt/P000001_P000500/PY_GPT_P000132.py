# problem title : Equilibrium Index
# Compare total minus the current/right sum with the running left sum.
n = int(input()); a = list(map(int, input().split()))[:n]
total = sum(a); left = 0; answer = -1
for i, x in enumerate(a):
    if left == total - left - x:
        answer = i; break
    left += x
print(answer)
