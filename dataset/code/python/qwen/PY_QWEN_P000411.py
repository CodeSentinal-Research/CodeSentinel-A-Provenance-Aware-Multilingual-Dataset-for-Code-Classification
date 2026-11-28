n = int(input())
records = [input().strip() for _ in range(n)]
keyword = input().strip()
for r in records:
    if keyword in r:
        print(r)
