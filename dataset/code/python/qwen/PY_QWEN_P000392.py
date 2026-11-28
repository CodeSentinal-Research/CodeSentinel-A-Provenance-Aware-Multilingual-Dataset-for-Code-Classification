n = int(input())
files = [input().strip() for _ in range(n)]
ext = input().strip()
for f in files:
    if f.endswith(ext):
        print(f)
