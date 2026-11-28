n = int(input())
vehs = []
for _ in range(n):
    vehs.append(input().split())
mfr = input().strip()
for v in vehs:
    if v[-1] == mfr:
        print(" ".join(v))
