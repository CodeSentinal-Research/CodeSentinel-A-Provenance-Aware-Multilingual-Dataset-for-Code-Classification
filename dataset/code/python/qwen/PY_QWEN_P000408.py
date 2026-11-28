n = int(input())
emails = [input().strip() for _ in range(n)]
domain = input().strip()
for e in emails:
    if e.endswith(domain):
        print(e)
