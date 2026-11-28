# problem title : Print All Factors
n = int(input())
print(*[i for i in range(1, n + 1) if n % i == 0])
