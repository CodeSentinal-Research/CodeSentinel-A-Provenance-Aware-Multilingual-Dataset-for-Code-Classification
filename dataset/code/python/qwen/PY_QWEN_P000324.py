s = input().strip()
print("Yes" if s in (s + s)[1:-1] else "No")
