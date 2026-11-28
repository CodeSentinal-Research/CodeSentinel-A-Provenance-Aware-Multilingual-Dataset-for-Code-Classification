# problem title : Calculate nPr
# nPr is the product of r consecutive integers descending from n.
n, r = map(int, input().split())
answer = 1
for x in range(n - r + 1, n + 1):
    answer *= x
print(answer)
