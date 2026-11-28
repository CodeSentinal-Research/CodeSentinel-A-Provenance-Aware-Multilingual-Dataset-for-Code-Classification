n = int(input())
accs = [input().split() for _ in range(n)]
months = int(input())
for a in accs:
    if int(a[-1]) > months:
        print(" ".join(a))
