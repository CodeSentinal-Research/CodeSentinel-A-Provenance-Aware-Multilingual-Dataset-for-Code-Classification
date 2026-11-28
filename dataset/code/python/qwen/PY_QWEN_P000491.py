m = int(input())
target = list(map(int, input().split()))
n = int(input())
res = []
curr = 1
for x in target:
    while curr < x:
        res.append("Push")
        res.append("Pop")
        curr += 1
    res.append("Push")
    curr += 1
print(" ".join(res))
