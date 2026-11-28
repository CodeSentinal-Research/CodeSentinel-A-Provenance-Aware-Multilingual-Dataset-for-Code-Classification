
n = int(input())
a = list(map(int, input().split()))
total = sum(a)
left = 0
for i, x in enumerate(a):
    if left == total - left - x:
        print(i); exit()
    left += x
print(-1)
