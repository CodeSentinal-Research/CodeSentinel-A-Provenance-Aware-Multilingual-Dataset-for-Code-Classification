n = int(input())
rests = [input().split() for _ in range(n)]
threshold = float(input())
for r in rests:
    if float(r[-1]) >= threshold:
        print(" ".join(r))
