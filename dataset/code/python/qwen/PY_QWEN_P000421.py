n = int(input())
mems = [input().split() for _ in range(n)]
curr_date = input().strip()
for m in mems:
    if m[-1] < curr_date:
        print(" ".join(m))
