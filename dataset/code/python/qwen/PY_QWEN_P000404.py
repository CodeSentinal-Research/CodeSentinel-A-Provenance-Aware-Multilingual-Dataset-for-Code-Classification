n = int(input())
docs = []
for _ in range(n):
    docs.append(input().split())
spec = input().strip()
for d in docs:
    if d[-1] == spec:
        print(" ".join(d))
