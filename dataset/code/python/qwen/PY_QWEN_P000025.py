n = input().strip()
if n[0] == '-':
    print("-" + n[:0:-1])
else:
    print(n[::-1])
