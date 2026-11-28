# problem title : Print Fibonacci Series
n = int(input())
a, b = 0, 1
ans = []
for _ in range(n):
    ans.append(a)
    a, b = b, a + b
print(*ans)
