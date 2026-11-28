n = input().strip()
if n == '0':
    print(1)
else:
    print(len(n) if n[0] != '-' else len(n) - 1)
