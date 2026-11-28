n = int(input())
vehs = [input().split() for _ in range(n)]
year = int(input())
for v in vehs:
    if int(v[-1]) > year:
        print(" ".join(v))
