n = int(input())
txns = {}
for _ in range(n):
    parts = input().split()
    txns[parts[0]] = " ".join(parts[1:])
tid = input().strip()
print(txns.get(tid, "Transaction Not Found"))
