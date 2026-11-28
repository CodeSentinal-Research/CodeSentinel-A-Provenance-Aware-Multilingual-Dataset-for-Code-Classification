s = input().strip()
t = input().strip()
print("Yes" if len(set(s)) == len(set(t)) == len(set(zip(s, t))) else "No")
