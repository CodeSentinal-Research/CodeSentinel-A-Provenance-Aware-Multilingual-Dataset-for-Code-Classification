n = int(input())
books = [input().split() for _ in range(n)]
author = input().strip()
genre = input().strip()
for b in books:
    if author in b and genre in b:
        print(" ".join(b))
