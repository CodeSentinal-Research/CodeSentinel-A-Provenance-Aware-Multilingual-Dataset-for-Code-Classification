s = input().strip()
k = int(input())
res = list(s)
for i in range(0, len(s), 2 * k):
    res[i:i+k] = reversed(res[i:i+k])
print("".join(res))
