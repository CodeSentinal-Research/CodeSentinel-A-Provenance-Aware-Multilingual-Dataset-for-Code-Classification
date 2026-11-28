n = int(input())
orders = []
for _ in range(n):
    orders.append(input().split())
status = input().strip()
for o in orders:
    if o[-1] == status:
        print(" ".join(o))
