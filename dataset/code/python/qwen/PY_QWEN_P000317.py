pattern = input().strip()
s = input().strip().split()
if len(pattern) != len(s):
    print("No")
else:
    print("Yes" if len(set(pattern)) == len(set(s)) == len(set(zip(pattern, s))) else "No")
