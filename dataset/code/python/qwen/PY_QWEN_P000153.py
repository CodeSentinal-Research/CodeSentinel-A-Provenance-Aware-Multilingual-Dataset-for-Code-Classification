n = int(input())
arr = list(map(int, input().split()))
pos = [x for x in arr if x >= 0]
neg = [x for x in arr if x < 0]
res = []
for i in range(max(len(pos), len(neg))):
    if i < len(pos):
        res.append(pos[i])
    if i < len(neg):
        res.append(neg[i])
print(" ".join(map(str, res)))
