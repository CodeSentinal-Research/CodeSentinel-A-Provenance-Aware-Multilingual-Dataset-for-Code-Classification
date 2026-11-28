n = int(input())
orders = [input().split() for _ in range(n)]
days = int(input())
for o in orders:
    if o[-2] == "Pending" and int(o[-1]) > days:
        print(" ".join(o))
