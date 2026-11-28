# problem title : Find Equilibrium Point
# Compare the running left sum with the sum remaining on the right.
n = int(input()); a = list(map(int, input().split()))[:n]
total = sum(a); left = 0; answer = -1
for i, value in enumerate(a):
    if left == total - left - value:
        answer = i + 1; break
    left += value
print(answer)
