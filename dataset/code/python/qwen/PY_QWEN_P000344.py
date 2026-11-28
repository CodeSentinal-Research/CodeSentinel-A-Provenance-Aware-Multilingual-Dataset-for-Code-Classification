words = input().split()
s = input().strip()
print(sum(1 for w in words if s.startswith(w)))
